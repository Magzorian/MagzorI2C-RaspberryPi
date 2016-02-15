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


#ifndef I2C_INTERFACE_CRC_H
#define	I2C_INTERFACE_CRC_H

#include "I2C_Interface.h"
#include "I2C_CRC.h"

#include "MLogger.h"
#include <string.h>

class I2C_Interface_CRC : public I2C_Interface{
public:
	static int write_with_crc(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint16_t microsecond_wr_delay = 0);
	static int read_with_crc(uint8_t i2c_address, uint8_t* r, uint8_t r_size);
	static int write_read_with_crc(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay = 0);
private:
	static void print_crc_error(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size);
	static const uint8_t CRC_BYTES_SIZE = 2;
	static const uint8_t CRC_READ_BYTES_SIZE = 2;
	static const uint8_t CRC_WRITE_BYTES_SIZE = 2;
	static const uint8_t COMMAND_CODE_BYTE_SIZE = 1;
        static const uint8_t RETRY_ATTEMPTS = 5;
};

#endif
