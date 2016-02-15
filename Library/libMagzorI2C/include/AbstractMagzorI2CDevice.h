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


#ifndef ABSTRACTMAGZORI2CDEVICE_H
#define	ABSTRACTMAGZORI2CDEVICE_H

#include "AbstractI2CDevice.h"
#include "I2C_Interface_CRC.h"
#include "Preprocessor_Directives.h"


class AbstractMagzorI2CDevice : public AbstractI2CDevice {
public:
	AbstractMagzorI2CDevice();
	AbstractMagzorI2CDevice(uint8_t i2c_address);
	
	int write_with_crc(uint8_t* w, uint8_t w_size, uint16_t microsecond_wr_delay = 0);
	int read_with_crc(uint8_t* r, uint8_t r_size);
	int write_read_with_crc(uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay = 0);
	
	uint16_t get_device_id();
	uint16_t get_device_version();
	void software_reset();
	
	virtual bool alert();
	bool is_alertable();
protected:
	static const uint8_t COMMAND_CODE_GET_DEVICE_ID         	= 0x02;
	static const uint8_t COMMAND_CODE_GET_DEVICE_VERSION   = 0x03;
	static const uint8_t COMMAND_CODE_SOFTWARE_RESET        	= 0x04;
	
	virtual void initDevice() {};
	bool alertable;
private:

};

#endif
