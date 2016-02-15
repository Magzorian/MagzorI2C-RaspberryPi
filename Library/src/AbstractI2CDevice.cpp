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


#include "AbstractI2CDevice.h"

AbstractI2CDevice::AbstractI2CDevice() {
}

AbstractI2CDevice::AbstractI2CDevice(uint8_t i2c_address){
	this->i2c_address = i2c_address;
}

int AbstractI2CDevice::write(uint8_t* w, uint8_t w_size){
	return I2C_Interface::i2c_write(i2c_address, w, w_size);
}

int AbstractI2CDevice::read(uint8_t* r, uint8_t r_size){
	return I2C_Interface::i2c_read(i2c_address, r, r_size);
}

int AbstractI2CDevice::write_read(uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay){
	return I2C_Interface::i2c_write_read(i2c_address, w, w_size, r, r_size, microsecond_wr_delay);
}
