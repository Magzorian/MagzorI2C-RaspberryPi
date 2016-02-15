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

#ifndef I2CDEVICE_IOBOARD_H
#define I2CDEVICE_IOBOARD_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XPin.h"
#include "XPin.h"

class XPin;

class I2CDevice_IOBoard : public AbstractMagzorI2CDevice{
	friend class I2CComm_XPin;
	
public:
	I2CDevice_IOBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_IOBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};

	XPin get_XPin(uint8_t pin_num);
	
	static const uint8_t VREF_1V5 = 15;
	static const uint8_t VREF_2V5 = 25;
	static const uint8_t VREF_3V3 = 33;
	static const uint8_t VREF_EXT = 255;
	
	bool setVRef(uint8_t vref);
	
	bool alert();
	
protected:

	
private:
	static const uint8_t PIN_COUNT = 10;
	static const uint8_t PIN_ARRAY[];
	
	static const uint8_t COMMAND_CODE_DIGITAL_WRITE 					= 0x19;
	static const uint8_t COMMAND_CODE_DIGITAL_READ 						= 0x21; 
	static const uint8_t COMMAND_CODE_ANALOG_WRITE 						= 0x20;
	static const uint8_t COMMAND_CODE_ANALOG_READ 						= 0x22; 
	static const uint8_t COMMAND_CODE_SET_VREF 								= 0x30;
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_SET 		= 0x25; 
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_CHECK 	= 0x26;
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_CLEAR 	= 0x27;

	I2CComm_XPin c_pin;
	void initDevice();
};


#endif
