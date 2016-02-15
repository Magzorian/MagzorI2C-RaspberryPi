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

#include "XStepper.h"

XStepper::XStepper(I2CComm_XStepper* comm, uint8_t stepper_num){
	this->comm = comm;
	this->stepper_num = stepper_num;
}

bool XStepper::set_pins(uint8_t pin0, uint8_t pin1){
	return comm->set_pins(stepper_num, pin0, pin1, UNASSIGNED_PIN, UNASSIGNED_PIN, UNASSIGNED_PIN);
}

bool XStepper::set_pins(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3){
	return comm->set_pins(stepper_num, pin0, pin1, pin2, pin3, UNASSIGNED_PIN);	
}

bool XStepper::set_speed(unsigned int steps_per_second){
	if(steps_per_second > 0 && steps_per_second <= 333){
		return comm->set_ticks_between_steps(stepper_num, (5000 / steps_per_second));
	}
	else if(steps_per_second > 333){
		return comm->set_ticks_between_steps(stepper_num, 15);
	}
	else{
		return false;
	}
}

bool XStepper::set_ticks_between_steps(unsigned int ticks_rate){
	return comm->set_ticks_between_steps(stepper_num, ticks_rate);
}

bool XStepper::set_ms_between_steps(unsigned int ms){
	//Check is ms is within range
	//(2^16-1)/5 = 13107
	if(ms < 13107){
		return comm->set_ticks_between_steps(stepper_num, ms*TICKS_PER_MS);
	}
	//Return false because it is out of range
	else{
		return false;
	}
}

bool XStepper::set_direction(uint8_t direction){
	return comm->set_direction(stepper_num, direction);
}

bool XStepper::step(unsigned int number_of_steps, func_cb call_back){
	return comm->step(stepper_num, number_of_steps, call_back);
}

bool XStepper::stop(){
	return comm->stop(stepper_num);
}
