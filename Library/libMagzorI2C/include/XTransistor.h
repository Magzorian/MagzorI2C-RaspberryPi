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

#ifndef XTRANSISTOR_H
#define XTRANSISTOR_H

#include <stdint.h>
#include "I2CComm_XTransistor.h"

class I2CComm_XTransistor;

class XTransistor{
	
public:
	XTransistor() {};
	XTransistor(I2CComm_XTransistor* comm, uint8_t transistor_num);

	static const bool ON = true;
	static const bool OFF = false;
	
	bool set(bool value);
	bool set_with_duty_cycle(uint8_t duty_cycle);
	bool enable();
	bool disable();

	uint8_t get_transistor_num();

protected:
	
private:
	I2CComm_XTransistor* comm;
	uint8_t transistor_num;
	
	void construct();
	
};

#endif
