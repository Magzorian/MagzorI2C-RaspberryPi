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

#ifndef I2CDEVICE_DARLINGTONARRAYBOARD_H
#define I2CDEVICE_DARLINGTONARRAYBOARD_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XTransistor.h"
#include "XTransistor.h"

class XTransistor;

class I2CDevice_DarlingtonArrayBoard : public AbstractMagzorI2CDevice{
	friend class I2CComm_XTransistor;
	
public:
	I2CDevice_DarlingtonArrayBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_DarlingtonArrayBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};

	XTransistor get_XTransistor(uint8_t transistor_num);
	
protected:

	
private:
	static const uint8_t TRANSISTOR_COUNT = 8;
	static const uint8_t TRANSISTOR_ARRAY[];
	
	static const uint8_t COMMAND_CODE_TRANSISTOR_SET 									= 0x19;
	static const uint8_t COMMAND_CODE_TRANSISTOR_SET_WITH_DUTY_CYCLE 	= 0x20; 


	I2CComm_XTransistor c_transistor;
	void initDevice();
};

#endif
