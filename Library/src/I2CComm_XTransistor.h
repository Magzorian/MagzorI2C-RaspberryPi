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


#ifndef I2CCOMM_XTRANSISTOR_H
#define I2CCOMM_XTRANSISTOR_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "XTransistor.h"

class XTransistor;

class I2CComm_XTransistor{
	friend class XTransistor;

public:
	~I2CComm_XTransistor(); //Deconstructor for stuff like func_cb array
	I2CComm_XTransistor(){};
	I2CComm_XTransistor(	AbstractMagzorI2CDevice* device, 
	const uint8_t* transistors, 
	uint8_t transistor_count,
	uint8_t command_code_transistor_set,
	uint8_t command_code_transistor_set_with_duty_cycle
	);

	XTransistor get_XTransistor(uint8_t transistor_num);
	
protected:	
	bool set(uint8_t transistor_num, bool value);
	bool set_with_duty_cycle(uint8_t transistor_num, uint8_t duty_cycle);
	
private:
	AbstractMagzorI2CDevice* device;
	const uint8_t* transistors;
	
	uint8_t transistor_count;
	
	uint8_t command_code_transistor_set;
	uint8_t command_code_transistor_set_with_duty_cycle;
};

#endif
