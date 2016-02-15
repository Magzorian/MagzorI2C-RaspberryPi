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

#include "I2CDevice_StepperBoard.h"

void I2CDevice_StepperBoard::initDevice(){
	c_stepper = I2CComm_XStepper(	this,
	STEPPER_COUNT,
	COMMAND_CODE_STEPPER_SETUP_PINS,
	COMMAND_CODE_STEPPER_SET_TICKS_BETWEEN_STEPS,
	COMMAND_CODE_STEPPER_SET_DIRECTION,
	COMMAND_CODE_STEPPER_STEP,
	COMMAND_CODE_STEPPER_STOP,
	COMMAND_CODE_STEPPER_INTERRUPT_CHECK,
	COMMAND_CODE_STEPPER_INTERRUPT_CLEAR
	);

	alertable = true;
}

XStepper I2CDevice_StepperBoard::get_XStepper(uint8_t stepper_num){
	if(stepper_num < STEPPER_COUNT){
		return c_stepper.get_XStepper(stepper_num);
	}
	else{
		return c_stepper.get_XStepper(255);
	}
}

bool I2CDevice_StepperBoard::alert(){
	return c_stepper.alert();
}
