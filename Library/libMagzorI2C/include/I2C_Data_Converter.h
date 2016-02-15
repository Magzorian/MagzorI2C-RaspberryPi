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


#ifndef I2C_DATA_CONVERTER_H
#define I2C_DATA_CONVERTER_H

#include <stdint.h>

class I2C_Data_Converter {
private:
	
protected:

public:
	static void put_uint8_t(uint8_t data, uint8_t* array, uint8_t index);
	static uint8_t get_uint8_t(uint8_t* array, uint8_t index);
	
	static void put_bool(bool data, uint8_t* array, uint8_t index);
	static bool get_bool(uint8_t* array, uint8_t index);
	
	static void put_uint16_t(uint16_t data, uint8_t* array, uint8_t starting_index);
	static uint16_t get_uint16_t(uint8_t* array, uint8_t starting_index);
};

#endif
