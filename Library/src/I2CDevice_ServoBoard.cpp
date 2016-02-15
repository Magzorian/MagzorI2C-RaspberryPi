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

#include "I2CDevice_ServoBoard.h"

void I2CDevice_ServoBoard::initDevice(){
	c_servo = I2CComm_XServo(this, SERVO_COUNT, COMMAND_CODE_SET_PWM, COMMAND_CODE_GET_PWM);
	alertable = false;
}

XServo I2CDevice_ServoBoard::get_XServo(uint8_t servo_num){
	if( servo_num < SERVO_COUNT ){
		return c_servo.get_XServo(servo_num);
	}
	else{
		return c_servo.get_XServo(255);
	}
}

