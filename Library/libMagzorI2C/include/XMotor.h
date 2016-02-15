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

#ifndef XMOTOR_H
#define XMOTOR_H

#include "I2CComm_XMotor.h"
#include <stdint.h>


class I2CComm_XMotor;

class XMotor{
	
public:
	static const uint8_t FORWARD = 0;
	static const uint8_t BACKWARD = 1;
	static const uint8_t FLIP = 2;
	
	XMotor();
	XMotor(I2CComm_XMotor* comm, uint8_t motor_num);
	
	bool set_direction(uint8_t direction);
	uint8_t get_direction();
	
	bool set_speed(uint8_t speed);
	uint8_t get_speed();
	
	bool stop();			//Set the speed to 0 at the current direction
	bool run();			//Set the speed to max at the current direction
	bool flip();			//Flips the polarity
	
protected:
	
private:
	I2CComm_XMotor* comm;
	uint8_t motor_num;
	
};

#endif
