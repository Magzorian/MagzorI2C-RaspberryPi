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

#include "I2CDevice_MotorBoard.h"

void I2CDevice_MotorBoard::initDevice(){
	c_motor = I2CComm_XMotor(this, MOTOR_COUNT, COMMAND_CODE_SET_DIR, COMMAND_CODE_GET_DIR, COMMAND_CODE_SET_SPD, COMMAND_CODE_GET_SPD);
	alertable = false;
}

XMotor I2CDevice_MotorBoard::get_XMotor(uint8_t motor_num){
	if( motor_num < MOTOR_COUNT ){
		return c_motor.get_XMotor(motor_num);
	}
	else
	return c_motor.get_XMotor(255);
}
