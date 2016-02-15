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


#include "I2CDevice_CompositeBoard.h"

//const uint8_t I2CDevice_CompositeBoard::PIN_ARRAY[] = {2, 5, 6, 7, 8, 19};
const uint8_t I2CDevice_CompositeBoard::PIN_ARRAY[] = {19, 8, 7, 2, 5, 6};

void I2CDevice_CompositeBoard::initDevice(){
	c_servo = I2CComm_XServo(this, SERVO_COUNT, COMMAND_CODE_SET_PWM, COMMAND_CODE_GET_PWM);
	c_motor = I2CComm_XMotor(this, MOTOR_COUNT, COMMAND_CODE_SET_DIR, COMMAND_CODE_GET_DIR, COMMAND_CODE_SET_SPD, COMMAND_CODE_GET_SPD);
	c_pin = I2CComm_XPin(	this, 
	PIN_ARRAY, 
	PIN_COUNT,
	COMMAND_CODE_DIGITAL_WRITE,
	COMMAND_CODE_DIGITAL_READ,
	COMMAND_CODE_ANALOG_WRITE,
	COMMAND_CODE_ANALOG_READ, 
	COMMAND_CODE_SET_VREF,
	COMMAND_CODE_DIGITAL_INTERRUPT_SET, 
	COMMAND_CODE_DIGITAL_INTERRUPT_CHECK,
	COMMAND_CODE_DIGITAL_INTERRUPT_CLEAR);
	alertable = true;
}

XServo I2CDevice_CompositeBoard::get_XServo(uint8_t servo_num){
	if( servo_num < SERVO_COUNT ){
		return c_servo.get_XServo(servo_num);
	}
	else{
		return c_servo.get_XServo(255);
	}
}


XMotor I2CDevice_CompositeBoard::get_XMotor(uint8_t motor_num){
	if( motor_num < MOTOR_COUNT ){
		return c_motor.get_XMotor(motor_num);
	}
	else
	return c_motor.get_XMotor(255);
}

XPin I2CDevice_CompositeBoard::get_XPin(uint8_t pin_num){
	if(pin_num < PIN_COUNT){
		return c_pin.get_XPin(pin_num);
	}
	else{
		return c_pin.get_XPin(255);
	}
}

bool I2CDevice_CompositeBoard::setVRef(uint8_t vref){
	return c_pin.setVRef(vref);
}

bool I2CDevice_CompositeBoard::alert(){
	return c_pin.alert();
}
