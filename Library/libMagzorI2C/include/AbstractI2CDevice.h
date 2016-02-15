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


#ifndef ABSTRACTI2CDEVICE_H
#define	ABSTRACTI2CDEVICE_H

#include "I2C_Interface.h"

class AbstractI2CDevice {
public:
	AbstractI2CDevice();
	AbstractI2CDevice(uint8_t i2c_address);
	
	int write(uint8_t* w, uint8_t w_size);
	int read(uint8_t* r, uint8_t r_size);
	int write_read(uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay = 0);

protected:
	uint8_t i2c_address;
private:
};

#endif
