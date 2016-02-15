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

#ifndef PREPROCESSOR_DIRECTIVES_H
#define	PREPROCESSOR_DIRECTIVES_H

// Energia
#if defined(ENERGIA) 
//#warning Preprocessor_Directives is using Energia variant.
#include "Preprocessor_Directives_Energia.h"

// Arduino 
#elif defined(ARDUINO)
//#warning Preprocessor_Directives is using Arduino variant.
#include "Preprocessor_Directives_Arduino.h"

// Default
#else
//#warning No specific Preprocessor Directive found. Preprocessor_Directives is using default variant.
#include "Preprocessor_Directives_Default.h"
#endif


#endif
