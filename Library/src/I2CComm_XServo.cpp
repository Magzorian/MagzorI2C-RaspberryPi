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


#include "I2CComm_XServo.h"

I2CComm_XServo::I2CComm_XServo(AbstractMagzorI2CDevice* device, uint8_t servo_count, uint8_t command_code_set_pwm, uint8_t command_code_get_pwm){
	this->device = device;
	this->servo_count = servo_count;
	this->command_code_set_pwm = command_code_set_pwm;
	this->command_code_get_pwm = command_code_get_pwm;
}

XServo I2CComm_XServo::get_XServo(uint8_t servo_num){
	if( servo_num < servo_count){
		return XServo(this, servo_num);
	}
	else
	{
		return XServo(this, 255);
	}
}

bool I2CComm_XServo::write_microseconds(uint8_t servo_num, uint16_t microseconds){
	uint8_t w[3];
	w[0] = command_code_set_pwm;
	w[1] = (servo_num << 5) | ((microseconds >> 8) & 0x1F);
	w[2] = microseconds & 0xFF;
	
	device->write_with_crc(w, 3, 10);
	
	return true;
}

uint16_t I2CComm_XServo::read_microseconds(uint8_t servo_num){
	uint8_t wr[2];
	wr[0] = command_code_get_pwm;
	wr[1] = servo_num;
	

	
	device->write_read_with_crc(wr, 2, wr, 2, 20);
	
	return (wr[0] << 8) | wr[1];
}
