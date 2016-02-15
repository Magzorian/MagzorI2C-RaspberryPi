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

#include "I2C_Data_Converter.h"

void I2C_Data_Converter::put_uint8_t(uint8_t data, uint8_t* array, uint8_t index){
	array[index] = data;
}

uint8_t I2C_Data_Converter::get_uint8_t(uint8_t* array, uint8_t index){
	return array[index];
}

void I2C_Data_Converter::put_bool(bool data, uint8_t* array, uint8_t index){
	if(data){
		array[index] = 0x01;
	}
	else{
		array[index] = 0x00;
	}
}

bool I2C_Data_Converter::get_bool(uint8_t* array, uint8_t index){
	if(array[index] == 0x01){
		return true;
	}
	else{
		return false;
	}
}

void I2C_Data_Converter::put_uint16_t(uint16_t data, uint8_t* array, uint8_t starting_index){
	array[starting_index] = (data >> 8) & 0xFF; 
	array[starting_index+1] = data & 0xFF;  
}

uint16_t I2C_Data_Converter::get_uint16_t(uint8_t* array, uint8_t starting_index){
	return ((array[starting_index] & 0xFF) << 8) | array[starting_index + 1];
}

