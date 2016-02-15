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

#ifndef I2CDEVICE_MOTORBOARD_H
#define I2CDEVICE_MOTORBOARD_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XMotor.h"
#include "XMotor.h"

class I2CComm_XMotor;

class I2CDevice_MotorBoard : public AbstractMagzorI2CDevice{
	
	friend class I2CComm_XMotor;
	
public:
	I2CDevice_MotorBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_MotorBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};

	XMotor get_XMotor(uint8_t motor_num);
	
protected:


private:
	void initDevice();
	
	static const uint8_t COMMAND_CODE_SET_DIR 	= 0x10;
	static const uint8_t COMMAND_CODE_SET_SPD 	= 0x11;
	static const uint8_t COMMAND_CODE_GET_DIR 	= 0x12;
	static const uint8_t COMMAND_CODE_GET_SPD 	= 0x13;
	
	I2CComm_XMotor c_motor;
	static const uint8_t MOTOR_COUNT = 2;
	
};

#endif
