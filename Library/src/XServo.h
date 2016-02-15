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

#ifndef XSERVO_H
#define	XSERVO_H

#include <stdint.h>
#include "I2CComm_XServo.h"

class I2CComm_XServo;

class XServo{
private:
	static const uint16_t MIN_PWM = 544;
	static const uint16_t MAX_PWM = 2400;
	static const uint16_t DEFAULT_MIN_PWM = 600;
	static const uint16_t DEFAULT_MAX_PWM = 2400;
	static const uint16_t DEFAULT_MIN_MAP = 0;
	static const uint16_t DEFAULT_MAX_MAP = 180;
	
	I2CComm_XServo* comm;
	uint8_t servo_num;
	
	void construct();
	
	uint16_t min_map;
	uint16_t max_map;
	
	uint16_t min_pwm;
	uint16_t max_pwm;
	
	static int map(long x, long in_min, long in_max, long out_min, long out_max);
	
	
protected:
	
public:
	XServo();
	XServo(I2CComm_XServo* comm, uint8_t servo_num);
	
	bool set_min_max_pwm(uint16_t min_pwm, uint16_t max_pwm);	
	
	//uint16_t get_min_pwm();
	//uint16_t get_max_pwm();
	
	bool set_map(int16_t min_map, int16_t max_map);
	
	//int16_t get_min_map();
	//int16_t get_max_map();
	
	bool write(int16_t value);
	int16_t read();
	
	bool write_microseconds(uint16_t microseconds);
	uint16_t read_microseconds();
	
	bool detach();
	
	
};

#endif
