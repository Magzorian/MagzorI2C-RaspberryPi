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

#include "I2CDevice_IOBoard.h"

const uint8_t I2CDevice_IOBoard::PIN_ARRAY[] = {19, 13, 2, 3, 4, 5, 6, 7, 9, 10};

void I2CDevice_IOBoard::initDevice(){
	
	c_pin = I2CComm_XPin(	this, 
	PIN_ARRAY, 
	PIN_COUNT,
	COMMAND_CODE_DIGITAL_WRITE,
	COMMAND_CODE_DIGITAL_READ,
	COMMAND_CODE_ANALOG_WRITE,
	COMMAND_CODE_ANALOG_READ, 
	COMMAND_CODE_SET_VREF,
	COMMAND_CODE_DIGITAL_INTERRUPT_SET, 
	COMMAND_CODE_DIGITAL_INTERRUPT_CHECK,
	COMMAND_CODE_DIGITAL_INTERRUPT_CLEAR);

	alertable = true;
}

XPin I2CDevice_IOBoard::get_XPin(uint8_t pin_num){
	if(pin_num < PIN_COUNT){
		return c_pin.get_XPin(pin_num);
	}
	else{
		return c_pin.get_XPin(255);
	}
}

bool I2CDevice_IOBoard::setVRef(uint8_t vref){
	return c_pin.setVRef(vref);
}

bool I2CDevice_IOBoard::alert(){
	return c_pin.alert();
}
