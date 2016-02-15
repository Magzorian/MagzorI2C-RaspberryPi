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

#ifndef MLOGGER_H
#define MLOGGER_H

// Energia
#if defined(ENERGIA) 
//#warning MLogger is using Arduino (Energia compatible) variant.
#include "MLogger_Arduino.h"

// Arduino 
#elif defined(ARDUINO)
//#warning MLogger is using Arduino variant.
#include "MLogger_Arduino.h"

//error, platform not defined
#else
//#warning No specific MLogger found. MLogger is using default variant.
#include "MLogger_Default.h"
#endif

#endif
