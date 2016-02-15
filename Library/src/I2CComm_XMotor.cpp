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


#include "I2CComm_XMotor.h"

I2CComm_XMotor::I2CComm_XMotor(AbstractMagzorI2CDevice* device, uint8_t motor_count, uint8_t command_code_set_dir, uint8_t command_code_get_dir, uint8_t command_code_set_spd, uint8_t command_code_get_spd){
	this->device = device;
	this->motor_count = motor_count;
	this->command_code_set_dir = command_code_set_dir;
	this->command_code_get_dir = command_code_get_dir;
	this->command_code_set_spd = command_code_set_spd;
	this->command_code_get_spd = command_code_get_spd;
}

XMotor I2CComm_XMotor::get_XMotor(uint8_t motor_num){
	if( motor_num < motor_count )
	return XMotor(this, motor_num);
	else
	return XMotor(this, 255);
}

bool I2CComm_XMotor::write_direction(uint8_t motor_num, uint8_t direction){
	uint8_t w[3];
	w[0] = command_code_set_dir;
	w[1] = motor_num;
	w[2] = direction;
	return device->write_with_crc(w, 3, 10);	
}

int8_t I2CComm_XMotor::read_direction(uint8_t motor_num){
	uint8_t wr[2];
	wr[0] = command_code_get_dir;
	wr[1] = motor_num;
	device->write_read_with_crc(wr, 2, wr, 2, 10);
	
	if( motor_num == wr[0] )
	return wr[1];
	else
	return -1;	//Error	
}

bool I2CComm_XMotor::write_speed(uint8_t motor_num, uint8_t speed){
	uint8_t w[3];
	w[0] = command_code_set_spd;
	w[1] = motor_num;
	w[2] = speed;
	return device->write_with_crc(w, 3, 10);	
}

int8_t I2CComm_XMotor::read_speed(uint8_t motor_num){
	uint8_t wr[2];
	wr[0] = command_code_get_spd;
	wr[1] = motor_num;
	device->write_read_with_crc(wr, 2, wr, 2, 10);
	
	if( motor_num == wr[0] )
	return wr[1];
	else
	return -1;	//Error	
}
