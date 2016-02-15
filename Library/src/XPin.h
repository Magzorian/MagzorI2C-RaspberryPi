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

#ifndef XPIN_H
#define XPIN_H

#include <stdint.h>
#include "I2CComm_XPin.h"

typedef void (*func_cb)(void);
class I2CComm_XPin;

class XPin{
	
public:
	XPin() {};
	XPin(I2CComm_XPin* comm, uint8_t pin_num);

	
	static const uint8_t RES_NONE = 0x00;			//I2CControl_Pins::RES_NONE; 
	static const uint8_t RES_PULLUP = 0x02;			//I2CControl_Pins::RES_PULLUP; 
	static const uint8_t RES_PULLDOWN = 0x04;	//I2CControl_Pins::RES_PULLDOWN;
	static const uint8_t EDGE_FALLING = 0x02;		//I2CControl_Pins::EDGE_FALLING;
	static const uint8_t EDGE_RISING = 0x03;		//I2CControl_Pins::EDGE_RISING;

	static const bool ON = true;
	static const bool OFF = false;
	
	bool digitalWrite(bool value);
	bool digitalRead(uint8_t res = RES_NONE);
	bool analogWrite(uint8_t value);
	uint16_t analogRead(uint8_t res = RES_NONE);
	
	bool setDigitalInterrupt(uint8_t interrupt_type, func_cb call_back, int8_t res = RES_NONE);
	bool detachDigitalInterrupt();
	
	uint8_t get_pin_num();

protected:
	
private:
	I2CComm_XPin* comm;
	uint8_t pin_num;
	
	void construct();
	
};

#endif
