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


#ifndef I2CCOMM_XSERVO_H
#define	I2CCOMM_XSERVO_H

#include "AbstractMagzorI2CDevice.h"
#include "XServo.h"
#include <stdint.h>

class XServo;
class I2CComm_XServo {
	friend class XServo;
	
public:
	I2CComm_XServo() {};
	I2CComm_XServo(AbstractMagzorI2CDevice* device, uint8_t servo_count, uint8_t command_code_set_pwm, uint8_t command_code_get_pwm);
	
	XServo get_XServo(uint8_t servo_num);
	
protected:
	bool write_microseconds(uint8_t _servo_num, uint16_t microseconds);
	uint16_t read_microseconds(uint8_t _servo_num);
	
private:
	AbstractMagzorI2CDevice* device;
	uint8_t servo_count;
	uint8_t command_code_set_pwm;
	uint8_t command_code_get_pwm;

};

#endif
