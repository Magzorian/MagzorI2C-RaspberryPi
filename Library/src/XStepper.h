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

#ifndef XSTEPPER_H
#define XSTEPPER_H

#include <stdint.h>
#include "I2CComm_XStepper.h"

typedef void (*func_cb)(void);
class I2CComm_XStepper;

class XStepper{
	
public:
	XStepper() {};
	XStepper(I2CComm_XStepper* comm, uint8_t stepper_num);

	static const uint8_t FORWARD = 0;
	static const uint8_t BACKWARD = 1;
	static const uint8_t FLIP = 2;
	
	bool set_pins(uint8_t pin0, uint8_t pin1);
	bool set_pins(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3);
	
	bool set_speed(unsigned int steps_per_second);
	bool set_ticks_between_steps(unsigned int ticks_rate);
	bool set_ms_between_steps(unsigned int ms);

	bool set_direction(uint8_t direction);
	
	bool step(unsigned int number_of_steps = 1, func_cb call_back = NULL);
	bool stop();
protected:
	
private:
	I2CComm_XStepper* comm;
	uint8_t stepper_num;
	
	void construct();
	
	static const uint8_t UNASSIGNED_PIN = 255;
	
	//0.2ms per tick, multiplier to convert requested ms to ticks
	static const uint8_t TICKS_PER_MS = 5;
	
	static const uint16_t TICKS_PER_SECOND = 5000;
};

#endif
