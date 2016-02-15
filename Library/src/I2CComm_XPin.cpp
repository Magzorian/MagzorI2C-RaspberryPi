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


#include "I2CComm_XPin.h"

I2CComm_XPin::~I2CComm_XPin(){
	
}

I2CComm_XPin::I2CComm_XPin(	AbstractMagzorI2CDevice* device, 
const uint8_t* pins, 
uint8_t pin_count,
uint8_t command_code_digital_write, 
uint8_t command_code_digital_read, 
uint8_t command_code_analog_write,
uint8_t command_code_analog_read, 
uint8_t command_code_set_vref, 
uint8_t command_code_digital_interrupt_set, 
uint8_t command_code_digital_interrupt_check, 
uint8_t command_code_digital_interrupt_clear){
	this->device = device;
	this->pins = pins;
	this->pin_count = pin_count;
	this->command_code_digital_write = command_code_digital_write;
	this->command_code_digital_read = command_code_digital_read;
	this->command_code_analog_write = command_code_analog_write;
	this->command_code_analog_read = command_code_analog_read;
	this->command_code_set_vref = command_code_set_vref;
	this->command_code_digital_interrupt_set = command_code_digital_interrupt_set;
	this->command_code_digital_interrupt_check = command_code_digital_interrupt_check;
	this->command_code_digital_interrupt_clear = command_code_digital_interrupt_clear;
	
	this->call_backs = new func_cb[pin_count];		//New function might cause problems?
	for(uint8_t i = 0; i < pin_count; ++i){					//Set all pointers to NULL
		call_backs[i] = NULL;
	}
}

bool I2CComm_XPin::digitalWrite(uint8_t pin_num, bool value){
	uint8_t w[3];
	w[0] = command_code_digital_write;
	w[1] = pins[pin_num];
	
	if(value)
	w[2] = 0x01;
	else
	w[2] = 0x00;
	
	return device->write_with_crc(w, 3, 10);
}

bool I2CComm_XPin::digitalRead(uint8_t pin_num, uint8_t res){
	uint8_t wr[3];
	wr[0] = command_code_digital_read;
	wr[1] = pins[pin_num];
	wr[2] = res;
	
	device->write_read_with_crc(wr, 3, wr, 2, 10);
	
	if(wr[1] == 0x01){
		return true;
	}
	else if(wr[1] == 0x00){
		return false;
	}
	else{
		return false; 		//Error case, response unknown.
	}
}

bool I2CComm_XPin::analogWrite(uint8_t pin_num, uint8_t value){
	uint8_t w[3];
	w[0] = command_code_analog_write;
	w[1] = pins[pin_num];
	w[2] = value;
	
	return device->write_with_crc(w, 3, 10);
}

uint16_t I2CComm_XPin::analogRead(uint8_t pin_num, uint8_t res){
	uint8_t wr[4];
	wr[0] = command_code_analog_read;
	wr[1] = pins[pin_num];
	wr[2] = res;
	
	device->write_read_with_crc(wr, 3, wr, 4, 800); //Delay 800 microseconds between request analog and reading analog value (allow microcontroller to read the analog signal)

	return (wr[2] << 8) | wr[3];
}

bool I2CComm_XPin::setVRef(uint8_t vref){
	uint8_t w[2];
	w[0] = command_code_set_vref;
	w[1] = vref;
	
	return device->write_with_crc(w, 2, 10);
}

bool I2CComm_XPin::setDigitalInterrupt(uint8_t pin_num, uint8_t interrupt_type, func_cb call_back, int8_t res){
	uint8_t w[4];
	w[0] = command_code_digital_interrupt_set;
	w[1] = pins[pin_num];
	w[2] = res;
	w[3] = interrupt_type;
	
	call_backs[pin_num] = call_back;
	
	return device->write_with_crc(w, 4, 50);
}

uint8_t I2CComm_XPin::checkDigitalInterrupt(){
	uint8_t wr[1];
	wr[0] = command_code_digital_interrupt_check;
	
	bool sucessfulRead = device->write_read_with_crc(wr, 1, wr, 1, 100); 			//May need to delay
	
	if(!sucessfulRead)
	return 255;
	
	//Search for the array position in the pin array, return this value
	for(int i = 0; i < pin_count; ++i){
		if(pins[i] == wr[0])
		return i;	//Return position in array
	}
	
	return 255;	//return 255, for no pin interrupted/no interrupt
}

bool I2CComm_XPin::detachDigitalInterrupt(uint8_t pin_num){
	//TODO
	return false;
}

bool I2CComm_XPin::clearDigitalInterrupt(uint8_t pin_num){
	uint8_t w[4];
	w[0] = command_code_digital_interrupt_clear;
	w[1] = pins[pin_num];
	
	return device->write_with_crc(w, 2, 100);
}

bool I2CComm_XPin::alert(){
	uint8_t interruptedPin;
	bool wasInterrupted = false;

	for(int i = 0; i < pin_count; ++i){
		interruptedPin = checkDigitalInterrupt();
		if( (interruptedPin != 255) && (interruptedPin < pin_count) ){
			//Call correct callback function
			clearDigitalInterrupt(interruptedPin);
			if(call_backs[interruptedPin] != NULL){
				func_cb temp_call_back = call_backs[interruptedPin];				//Temp store callback pointer, because the actual callback could rewrite a new callback				
				call_backs[interruptedPin] = NULL;											//Set callback pointer to NULL (clear), this can be set in the actual callback		
				temp_call_back();																	//call the actual callback	
			}
			wasInterrupted = true;
		}
		else{			//No interrupts or no additional interrupts triggered, break
			break;
		}
	}
	
	return wasInterrupted;
}

XPin I2CComm_XPin::get_XPin(uint8_t pin_num){
	if( pin_num < pin_count )
	return XPin(this, pin_num);
	else
	return XPin(this, 255);
}
