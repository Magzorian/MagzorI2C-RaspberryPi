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

#if defined(RASPBERRYPI)

#ifndef MAGZORI2C_RASPBERRYPI_H
#define MAGZORI2C_RASPBERRYPI_H

#include "MLogger.h"
#include "Preprocessor_Directives.h"
#include "AbstractMagzorI2CDevice.h"
#include "AlertObserver.h"
#include <wiringPi.h>

class MagzorI2C {
private:
	static bool initialized;

	static uint8_t reset_pin;
	static uint8_t interrupt_pin;

	static const uint8_t CLEAR_MAX_ATTEMPTS = 10;

	static void init();

protected:

public:
	static void setup(uint8_t reset_pin, uint8_t interrupt_pin);
	static void clear_i2c();
	static void hardware_reset_i2c_devices();
	static void register_i2c_device(AbstractMagzorI2CDevice* device);
	static void register_i2c_device(AbstractMagzorI2CDevice& device);
	static void interrupt_callback();

	static const uint8_t UNASSIGNED_PIN = 255;
};

#endif

#endif