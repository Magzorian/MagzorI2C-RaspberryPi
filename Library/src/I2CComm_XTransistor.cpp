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


#include "I2CComm_XTransistor.h"

I2CComm_XTransistor::~I2CComm_XTransistor(){
	
}

I2CComm_XTransistor::I2CComm_XTransistor(	AbstractMagzorI2CDevice* device, 
const uint8_t* transistors, 
uint8_t transistor_count,
uint8_t command_code_transistor_set,
uint8_t command_code_transistor_set_with_duty_cycle
){

	this->device = device;
	this->transistors = transistors;
	this->transistor_count = transistor_count;
	this->command_code_transistor_set = command_code_transistor_set;
	this->command_code_transistor_set_with_duty_cycle = command_code_transistor_set_with_duty_cycle;
}

bool I2CComm_XTransistor::set(uint8_t transistor_num, bool value){
	uint8_t w[3];
	w[0] = command_code_transistor_set;
	w[1] = transistors[transistor_num];
	
	if(value)
	w[2] = 0x01;
	else
	w[2] = 0x00;
	
	return device->write_with_crc(w, 3, 10);
}


bool I2CComm_XTransistor::set_with_duty_cycle(uint8_t transistor_num, uint8_t duty_cycle){
	uint8_t w[3];
	w[0] = command_code_transistor_set_with_duty_cycle;
	w[1] = transistors[transistor_num];
	w[2] = duty_cycle;
	
	return device->write_with_crc(w, 3, 10);
}

XTransistor I2CComm_XTransistor::get_XTransistor(uint8_t transistor_num){
	if( transistor_num < transistor_count )
	return XTransistor(this, transistor_num);
	else
	return XTransistor(this, 255);
}
