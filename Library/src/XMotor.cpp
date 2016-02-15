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

#include "XMotor.h"

XMotor::XMotor(){
	this->motor_num = 255;
}

XMotor::XMotor(I2CComm_XMotor* comm, uint8_t motor_num){
	this->comm = comm;
	this->motor_num = motor_num;
}

bool XMotor::set_direction(uint8_t direction){
	return comm->write_direction(motor_num, direction);
}

uint8_t XMotor::get_direction(){
	return comm->read_direction(motor_num);
}

bool XMotor::set_speed(uint8_t speed){
	return comm->write_speed(motor_num, speed);
}

uint8_t XMotor::get_speed(){
	return comm->read_speed(motor_num);
}

bool XMotor::stop(){
	return comm->write_speed(motor_num, 0);
}		

bool XMotor::run(){
	return comm->write_speed(motor_num, 255);
}		

bool XMotor::flip(){
	return comm->write_direction(motor_num, FLIP);
}
