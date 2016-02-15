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

#include "XPin.h"


XPin::XPin(I2CComm_XPin* comm, uint8_t pin_num){
	this->comm = comm;
	this->pin_num = pin_num;
}

bool XPin::digitalWrite(bool value){
	return comm->digitalWrite(pin_num, value);
}

bool XPin::digitalRead(uint8_t res){
	return comm->digitalRead(pin_num, res);
}

bool XPin::analogWrite(uint8_t value){
	return comm->analogWrite(pin_num, value);
	
}

uint16_t XPin::analogRead(uint8_t res){
	return comm->analogRead(pin_num, res);
}

bool XPin::setDigitalInterrupt(uint8_t interrupt_type, func_cb call_back, int8_t res){
	return comm->setDigitalInterrupt(pin_num, interrupt_type, call_back, res);
}

bool XPin::detachDigitalInterrupt(){
	return comm->detachDigitalInterrupt(pin_num);
}

uint8_t XPin::get_pin_num(){
	return pin_num;
}
