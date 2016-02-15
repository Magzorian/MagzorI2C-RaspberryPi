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


#ifndef I2CCOMM_XPIN_H
#define I2CCOMM_XPIN_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "XPin.h"

typedef void (*func_cb)(void);
class XPin;

class I2CComm_XPin{
	friend class XPin;

public:
	~I2CComm_XPin(); //Deconstructor for stuff like func_cb array
	I2CComm_XPin(){};
	I2CComm_XPin(	AbstractMagzorI2CDevice* device, 
	const uint8_t* pins, 
	uint8_t pin_count,
	uint8_t command_code_digital_write, 
	uint8_t command_code_digital_read, 
	uint8_t command_code_analog_write,
	uint8_t command_code_analog_read, 
	uint8_t command_code_set_vref, 
	uint8_t command_code_digital_interrupt_set, 
	uint8_t command_code_digital_interrupt_check, 
	uint8_t command_code_digital_interrupt_clear
	);

	bool setVRef(uint8_t vref);
	bool clearDigitalInterrupt(uint8_t pin_num);
	bool alert();

	XPin get_XPin(uint8_t pin_num);
	
protected:
	static const uint8_t RES_NONE 		= 0x00;
	static const uint8_t RES_PULLUP 		= 0x02;
	static const uint8_t RES_PULLDOWN = 0x04;
	
	static const uint8_t EDGE_FALLING 	= 0x02;
	static const uint8_t EDGE_RISING 	= 0x03;
	
	static const uint8_t VREF_1V5 			= 15;
	static const uint8_t VREF_2V5 			= 25;
	static const uint8_t VREF_3V3 			= 33;
	static const uint8_t VREF_EXT 			= 255;
	
	bool digitalWrite(uint8_t pin_num, bool value);
	bool digitalRead(uint8_t pin_num, uint8_t res);
	bool analogWrite(uint8_t pin_num, uint8_t value);
	uint16_t analogRead(uint8_t pin_num, uint8_t res);
	
	bool setDigitalInterrupt(uint8_t pin_num, uint8_t interrupt_type, func_cb call_back, int8_t res = RES_NONE);
	bool detachDigitalInterrupt(uint8_t pin_num);
	
	uint8_t checkDigitalInterrupt();
	
private:
	AbstractMagzorI2CDevice* device;
	const uint8_t* pins;
	
	uint8_t pin_count;
	
	uint8_t command_code_digital_write;
	uint8_t command_code_digital_read;
	uint8_t command_code_analog_write;
	uint8_t command_code_analog_read;
	
	uint8_t command_code_set_vref;
	uint8_t command_code_digital_interrupt_set;
	uint8_t command_code_digital_interrupt_check;
	uint8_t command_code_digital_interrupt_clear;
	uint8_t command_code_digital_interrupt_debounce_set;
	
	//Callbacks
	func_cb * call_backs;
};

#endif
