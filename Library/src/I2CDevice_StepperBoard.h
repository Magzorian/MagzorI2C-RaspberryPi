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

#ifndef I2CDEVICE_STEPPERBOARD_H
#define I2CDEVICE_STEPPERBOARD_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "I2CComm_XStepper.h"
#include "XStepper.h"

class XStepper;

class I2CDevice_StepperBoard : public AbstractMagzorI2CDevice{
	friend class I2CComm_XStepper;
	
public:
	I2CDevice_StepperBoard() : AbstractMagzorI2CDevice() {initDevice();};
	I2CDevice_StepperBoard(uint8_t i2c_address) : AbstractMagzorI2CDevice(i2c_address) {initDevice();};

	XStepper get_XStepper(uint8_t stepper_num);
	
	bool alert();
protected:

	
private:
	static const uint8_t STEPPER_COUNT = 1;
	
	static const uint8_t COMMAND_CODE_STEPPER_SETUP_PINS 							= 0x10;
	static const uint8_t COMMAND_CODE_STEPPER_SET_TICKS_BETWEEN_STEPS 	= 0x11;
	static const uint8_t COMMAND_CODE_STEPPER_SET_DIRECTION 						= 0x12;
	static const uint8_t COMMAND_CODE_STEPPER_STEP 										= 0x13;
	static const uint8_t COMMAND_CODE_STEPPER_STOP										= 0x14;
	static const uint8_t COMMAND_CODE_STEPPER_INTERRUPT_CHECK 					= 0x20;
	static const uint8_t COMMAND_CODE_STEPPER_INTERRUPT_CLEAR 					= 0x21;

	I2CComm_XStepper c_stepper;
	void initDevice();
};


#endif