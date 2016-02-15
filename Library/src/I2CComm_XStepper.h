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


#ifndef I2CCOMM_XSTEPPER_H
#define I2CCOMM_XSTEPPER_H

#include <stdint.h>
#include "AbstractMagzorI2CDevice.h"
#include "XStepper.h"
#include "I2C_Data_Converter.h"

typedef void (*func_cb)(void);
class XStepper;

class I2CComm_XStepper{
	friend class XStepper;
	
public:
	I2CComm_XStepper(){};
	I2CComm_XStepper(		AbstractMagzorI2CDevice* device, 
	uint8_t stepper_count,
	uint8_t command_code_stepper_setup_pins,
	uint8_t command_code_stepper_set_ticks_between_steps,
	uint8_t command_code_stepper_set_direction,
	uint8_t command_code_stepper_step,
	uint8_t command_code_stepper_stop,
	uint8_t command_code_stepper_interrupt_check,
	uint8_t command_code_stepper_interrupt_clear
	);
	
	bool alert();
	bool clearInterrupt(uint8_t stepper_num);
	
	XStepper get_XStepper(uint8_t stepper_num);

protected:
	bool set_pins(uint8_t stepper_num, uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);

	bool set_ticks_between_steps(uint8_t stepper_num, unsigned int ticks_rate);

	bool set_direction(uint8_t stepper_num, uint8_t direction);
	bool step(uint8_t stepper_num, unsigned int number_of_steps = 1, func_cb call_back = NULL);
	
	bool stop(uint8_t stepper_num);
	
	uint8_t checkInterrupt();
	
private:
	AbstractMagzorI2CDevice* device;
	uint8_t stepper_count;

	uint8_t command_code_stepper_setup_pins;
	uint8_t command_code_stepper_set_ticks_between_steps;
	uint8_t command_code_stepper_set_direction;
	uint8_t command_code_stepper_step;
	uint8_t command_code_stepper_stop;
	uint8_t command_code_stepper_interrupt_check;
	uint8_t command_code_stepper_interrupt_clear;
	
	func_cb * call_backs;
	
	static const uint8_t NO_INTERRUPT_PENDING = 0xff;
	
	static const uint8_t SUCCESSFUL = 0x00;

	static const uint8_t FAILURE_GENERAL = 0x01;
	static const uint8_t FAILURE_UNINITIALIZED_STEPPER = 0x02;
	static const uint8_t FAILURE_STEPPER_NUMBER_OUT_OF_RANGE = 0x03;
	static const uint8_t FAILURE_INCORRECT_PIN_SETUP = 0x04;

};

#endif
