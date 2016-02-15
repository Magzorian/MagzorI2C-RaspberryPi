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


#ifndef I2CDEVICE_COMPOSITEBOARD_H
#define I2CDEVICE_COMPOSITEBOARD_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XServo.h"
#include "XServo.h"
#include "I2CComm_XMotor.h"
#include "XMotor.h"
#include "I2CComm_XPin.h"
#include "XPin.h"

class XServo;
class XMotor;
class XPin;

class I2CDevice_CompositeBoard : public AbstractMagzorI2CDevice{
	friend class I2CComm_XServo;
	friend class I2CComm_XMotor;
	friend class I2CComm_XPin;
	
public:
	I2CDevice_CompositeBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_CompositeBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};
	
	//Servo stuff
	XServo get_XServo(uint8_t servo_num);
	
	//Motor stuff
	XMotor get_XMotor(uint8_t motor_num);
	
	//Pin stuff
	XPin get_XPin(uint8_t pin_num);
	
	static const uint8_t VREF_1V5 = 15;
	static const uint8_t VREF_2V5 = 25;
	static const uint8_t VREF_3V3 = 33;
	static const uint8_t VREF_EXT = 255;
	
	bool setVRef(uint8_t vref);
	
	bool alert();
protected:
	
private:
	//Servo stuff
	static const uint8_t COMMAND_CODE_SET_PWM	= 0x10;
	static const uint8_t COMMAND_CODE_GET_PWM	= 0x11;
	
	static const uint8_t SERVO_COUNT = 2;
	I2CComm_XServo c_servo;

	//Motor stuff
	static const uint8_t COMMAND_CODE_SET_DIR	= 0x12;
	static const uint8_t COMMAND_CODE_SET_SPD	= 0x13;
	static const uint8_t COMMAND_CODE_GET_DIR	= 0x14;
	static const uint8_t COMMAND_CODE_GET_SPD	= 0x15;
	

	static const uint8_t MOTOR_COUNT = 1;
	I2CComm_XMotor c_motor;
	
	//Pin Stuff
	static const uint8_t COMMAND_CODE_DIGITAL_WRITE 					= 0x19;
	static const uint8_t COMMAND_CODE_DIGITAL_READ 						= 0x21; 
	static const uint8_t COMMAND_CODE_ANALOG_WRITE 						= 0x20;
	static const uint8_t COMMAND_CODE_ANALOG_READ 						= 0x22; 
	static const uint8_t COMMAND_CODE_SET_VREF 								= 0x30;
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_SET 		= 0x25; 
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_CHECK 	= 0x26;
	static const uint8_t COMMAND_CODE_DIGITAL_INTERRUPT_CLEAR 	= 0x27;

	static const uint8_t PIN_COUNT = 6;
	static const uint8_t PIN_ARRAY[];
	I2CComm_XPin c_pin;

	//Device stuff
	void initDevice();
};

#endif
