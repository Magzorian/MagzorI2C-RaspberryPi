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

#include "I2CDevice_DarlingtonArrayBoard.h"

const uint8_t I2CDevice_DarlingtonArrayBoard::TRANSISTOR_ARRAY[] = {9, 8, 7, 6, 5, 4, 3, 2};

void I2CDevice_DarlingtonArrayBoard::initDevice(){
	
	c_transistor = I2CComm_XTransistor(	this, 
	TRANSISTOR_ARRAY,
	TRANSISTOR_COUNT,
	COMMAND_CODE_TRANSISTOR_SET,
	COMMAND_CODE_TRANSISTOR_SET_WITH_DUTY_CYCLE
	);
	alertable = false;
}

XTransistor I2CDevice_DarlingtonArrayBoard::get_XTransistor(uint8_t transistor_num){
	if(transistor_num < TRANSISTOR_COUNT){
		return c_transistor.get_XTransistor(transistor_num);
	}
	else{
		return c_transistor.get_XTransistor(255);
	}
}
