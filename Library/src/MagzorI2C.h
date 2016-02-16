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

#ifndef MAGZORI2C_H
#define MAGZORI2C_H

//Raspberry Pi
#if defined(RASPBERRYPI)
//#warning MagzorI2C is using RaspberryPi variant.
#include "MagzorI2C_RaspberryPi.h"

// Energia
#elif defined(ENERGIA) 
//#warning MagzorI2C is using Arduino (Energia compatible) variant.
#include "MagzorI2C_Arduino.h"

// Arduino 
#elif defined(ARDUINO)
//#warning MagzorI2C is using Arduino variant.
#include "MagzorI2C_Arduino.h"

// Error, platform not defined
#else
#error MagzorI2C is undefined!
#endif

#include "AbstractI2CDevice.h"
#include "AbstractMagzorI2CDevice.h"

#include "I2CDevice_ServoBoard.h"
#include "I2CDevice_MotorBoard.h"
#include "I2CDevice_IOBoard.h"
#include "I2CDevice_CompositeBoard.h"
#include "I2CDevice_DarlingtonArrayBoard.h"
#include "I2CDevice_StepperBoard.h"

#include "I2CComm_XServo.h"
#include "XServo.h"

#include "I2CComm_XMotor.h"
#include "XMotor.h"

#include "I2CComm_XPin.h"
#include "XPin.h"

#include "I2CComm_XStepper.h"
#include "XStepper.h"

#include "I2CComm_XTransistor.h"
#include "XTransistor.h"

#include "I2CDevice_MPU6050.h"

#endif
