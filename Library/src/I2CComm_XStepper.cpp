/*
* This file is part of the Magzor I2C Library.
*
* The Magzor I2C Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser  General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* The Magzor I2C Library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser  General Public License for more details.
*
* You should have received a copy of the GNU Lesser  General Public License
* along with the Magzor I2C Library.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "I2CComm_XStepper.h"

I2CComm_XStepper::I2CComm_XStepper(	AbstractMagzorI2CDevice* device, 
uint8_t stepper_count,
uint8_t command_code_stepper_setup_pins,
uint8_t command_code_stepper_set_ticks_between_steps,
uint8_t command_code_stepper_set_direction,
uint8_t command_code_stepper_step,
uint8_t command_code_stepper_stop,
uint8_t command_code_stepper_interrupt_check,
uint8_t command_code_stepper_interrupt_clear
){
	this->device = device;
	this->stepper_count = stepper_count;
	
	this->command_code_stepper_setup_pins = command_code_stepper_setup_pins;
	this->command_code_stepper_set_ticks_between_steps = command_code_stepper_set_ticks_between_steps;
	this->command_code_stepper_set_direction = command_code_stepper_set_direction;
	this->command_code_stepper_step = command_code_stepper_step;
	this->command_code_stepper_stop = command_code_stepper_stop;
	this->command_code_stepper_interrupt_check = command_code_stepper_interrupt_check;
	this->command_code_stepper_interrupt_clear = command_code_stepper_interrupt_clear;
	
	this->call_backs = new func_cb[stepper_count];		//New function might cause problems?
	for(uint8_t i = 0; i < stepper_count; ++i){				//Set all pointers to NULL
		call_backs[i] = NULL;
	}
}

XStepper I2CComm_XStepper::get_XStepper(uint8_t stepper_num){
	if( stepper_num < stepper_count){
		return XStepper(this, stepper_num);
	}
	else{
		return XStepper(this, 255);
	}
}

bool I2CComm_XStepper::set_pins(uint8_t stepper_num, uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4){
	uint8_t wr[7];
	
	wr[0] = command_code_stepper_setup_pins;
	wr[1] = stepper_num;
	wr[2] = pin0;
	wr[3] = pin1;
	wr[4] = pin2;
	wr[5] = pin3;
	wr[6] = pin4;
	
	int retval = device->write_read_with_crc(wr, 7, wr, 1, 100);
	
	if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
		return true;
	}
	else{
		return false;
	}
}

bool I2CComm_XStepper::set_ticks_between_steps(uint8_t stepper_num, unsigned int ticks_rate){
	uint8_t wr[4];
	
	wr[0] = command_code_stepper_set_ticks_between_steps;
	wr[1] = stepper_num;
	I2C_Data_Converter::put_uint16_t(ticks_rate, wr, 2);
	
	int retval = device->write_read_with_crc(wr, 4, wr, 1, 10);
	
	if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
		return true;
	}
	else{
		return false;
	}
}

bool I2CComm_XStepper::set_direction(uint8_t stepper_num, uint8_t direction){
	uint8_t wr[3];
	
	wr[0] = command_code_stepper_set_direction;
	wr[1] = stepper_num;
	wr[2] = direction;
	
	int retval = device->write_read_with_crc(wr, 3, wr, 1);
	
	if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
		return true;
	}
	else{
		return false;
	}
}

bool I2CComm_XStepper::step(uint8_t stepper_num, unsigned int number_of_steps, func_cb call_back){
	//check if stepper_num is within range of stepper_count
	if(stepper_num < stepper_count){
		uint8_t wr[4];
		wr[0] = command_code_stepper_step;
		wr[1] = stepper_num;
		I2C_Data_Converter::put_uint16_t(number_of_steps, wr, 2);
		
		int retval = device->write_read_with_crc(wr, 4, wr, 1, 50); 
		
		if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
			call_backs[stepper_num] = call_back;
			return true;
		}
		else{
			return false;
		}
	}
	//stepper_num falls out of range of stepper_count
	else{
		return false;
	}
}

bool I2CComm_XStepper::stop(uint8_t stepper_num){
	uint8_t wr[2];
	
	wr[0] = command_code_stepper_stop;
	wr[1] = stepper_num;
	
	int retval = device->write_read_with_crc(wr, 2, wr, 1);
	
	if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
		return true;
	}
	else{
		return false;
	}
}

bool I2CComm_XStepper::alert(){
	uint8_t interruptedStepper;
	bool wasInterrupted = false;
	
	for(int i = 0; i < stepper_count; ++i){
		interruptedStepper = checkInterrupt();
		if( (interruptedStepper != NO_INTERRUPT_PENDING) && (interruptedStepper < stepper_count) ){
			clearInterrupt(interruptedStepper);
			if(call_backs[interruptedStepper] != NULL){
				func_cb temp_call_back = call_backs[interruptedStepper];			//Temp store callback pointer, because the actual callback could rewrite a new callback	
				call_backs[interruptedStepper] = NULL;										//Set callback pointer to NULL (clear), this can be set in the actual callback		
				temp_call_back();																		//call the actual callback			
			}
			wasInterrupted = true;
		}
		else{
			break;
		}
	}
}

uint8_t I2CComm_XStepper::checkInterrupt(){
	uint8_t wr[1];
	wr[0] = command_code_stepper_interrupt_check;
	
	int retval = device->write_read_with_crc(wr, 1, wr, 1, 100);
	
	if( (retval == 1) && wr[0] != NO_INTERRUPT_PENDING){
		return wr[0];
	}
	else{
		return NO_INTERRUPT_PENDING;
	}
}

bool I2CComm_XStepper::clearInterrupt(uint8_t stepper_num){
	uint8_t wr[2];
	
	wr[0] = command_code_stepper_interrupt_clear;
	wr[1] = stepper_num;
	
	int retval = device->write_read_with_crc(wr, 2, wr, 1);
	
	if( (retval == 1) && (wr[0] == SUCCESSFUL) ){
		return true;
	}
	else{
		return false;
	}
}
