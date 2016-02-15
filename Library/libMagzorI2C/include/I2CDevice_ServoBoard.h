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

#ifndef I2CDEVICE_SERVOBOARD_H
#define	I2CDEVICE_SERVOBOARD_H

#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XServo.h"
#include "XServo.h"


class XServo;
class I2CDevice_ServoBoard : public AbstractMagzorI2CDevice {
	friend class I2CComm_XServo;

public:
	I2CDevice_ServoBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_ServoBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};
	
	XServo get_XServo(uint8_t servo_num);

protected:	

	
private:
	void initDevice();

	static const uint8_t COMMAND_CODE_SET_PWM = 0x10;
	static const uint8_t COMMAND_CODE_GET_PWM = 0x11;
	
	I2CComm_XServo c_servo;
	static const uint8_t SERVO_COUNT = 8;

};

#endif
