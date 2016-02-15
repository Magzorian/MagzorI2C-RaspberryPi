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

#ifndef I2C_CRC_H
#define	I2C_CRC_H

#include <stdint.h>
#include "Preprocessor_Directives.h"

class I2C_CRC {
public:
	static void put_crc(uint8_t* data, uint8_t data_start_index, uint8_t length, uint8_t* write_array, uint8_t crc_start_index);
	static bool check_crc_equal(uint8_t* crc_array1, uint8_t* crc_array2);

private:
	static uint16_t get_crc(uint8_t* data, uint8_t data_size);
	static void put_crc_into_array(uint16_t crc, uint8_t* write_array, uint8_t start_index);
};

#endif
