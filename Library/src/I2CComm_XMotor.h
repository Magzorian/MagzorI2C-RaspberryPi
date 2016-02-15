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


#ifndef I2CCOMM_XMOTOR_H
#define I2CCOMM_XMOTOR_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "XMotor.h"

class XMotor;

class I2CComm_XMotor{
	friend class XMotor;
	
public:
	I2CComm_XMotor(){};
	I2CComm_XMotor(AbstractMagzorI2CDevice* device, uint8_t motor_count, uint8_t command_code_set_dir, uint8_t command_code_get_dir, uint8_t command_code_set_spd, uint8_t command_code_get_spd);
	
	XMotor get_XMotor(uint8_t motor_num);
	
protected:
	bool write_direction(uint8_t motor_num, uint8_t direction);
	int8_t read_direction(uint8_t motor_num);
	
	bool write_speed(uint8_t motor_num, uint8_t speed);
	int8_t read_speed(uint8_t motor_num);
	
private:
	AbstractMagzorI2CDevice* device;
	uint8_t motor_count;
	uint8_t command_code_set_dir;
	uint8_t command_code_get_dir;
	uint8_t command_code_set_spd;
	uint8_t command_code_get_spd;

};

#endif
