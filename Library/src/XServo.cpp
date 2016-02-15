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

#include "XServo.h"

void XServo::construct(){
	set_min_max_pwm(DEFAULT_MIN_PWM, DEFAULT_MAX_PWM);
	set_map(DEFAULT_MIN_MAP, DEFAULT_MAX_MAP);
}

XServo::XServo(){
	construct();
}

XServo::XServo(I2CComm_XServo* comm, uint8_t servo_num){
	construct();
	this->comm = comm;
	this->servo_num = servo_num;
}

bool XServo::set_min_max_pwm(uint16_t min_pwm, uint16_t max_pwm){
	if(	(min_pwm < max_pwm) & 
			(MIN_PWM <= min_pwm) & 
			(max_pwm <= MAX_PWM)){	
		this->min_pwm = min_pwm;
		this->max_pwm = max_pwm;	
		return true;
	}
	else{
		return false;
	}
}

bool XServo::set_map(int16_t min_map, int16_t max_map){
	if(min_map < max_map){
		this->min_map = min_map;
		this->max_map = max_map;
		return true;
	}
	else{
		return false;
	}
}

bool XServo::write(int16_t value){
	return write_microseconds(map(value, min_map, max_map, min_pwm, max_pwm));
}

int16_t XServo::read(){
	return map(read_microseconds(), min_pwm, max_pwm, min_map, max_map);
}

bool XServo::write_microseconds(uint16_t microseconds){
	return comm->write_microseconds(servo_num, microseconds);
}
uint16_t XServo::read_microseconds(){
	return comm->read_microseconds(servo_num);
}

bool XServo::detach(){
	write_microseconds(0);
	return true;
}

int XServo::map(long x, long in_min, long in_max, long out_min, long out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
