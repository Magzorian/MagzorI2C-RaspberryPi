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

#include "XTransistor.h"

XTransistor::XTransistor(I2CComm_XTransistor* comm, uint8_t transistor_num){
	this->comm = comm;
	this->transistor_num = transistor_num;
}

bool XTransistor::set(bool value){
	return comm->set(transistor_num, value);
}

bool XTransistor::set_with_duty_cycle(uint8_t duty_cycle){
	return comm->set_with_duty_cycle(transistor_num, duty_cycle);
	
}

bool XTransistor::enable(){
	return set(true);
}

bool XTransistor::disable(){
	return set(false);
}

uint8_t XTransistor::get_transistor_num(){
	return transistor_num;
}
