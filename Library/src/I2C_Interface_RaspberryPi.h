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
#ifndef I2C_INTERFACE_RASPBERRYPI_H
#define	I2C_INTERFACE_RASPBERRYPI_H

#include <stdint.h>
#include "Preprocessor_Directives.h"
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <wiringPiI2C.h>
#include <pthread.h>
#include <algorithm>

#include "MLogger.h"

class I2C_Interface {
	friend class I2C_Interface_CRC;
public:
	//init function
	static void init();
	
	static int i2c_write(uint8_t i2c_address, uint8_t* w, uint8_t w_size, bool lock = true);
	static int i2c_read(uint8_t i2c_address, uint8_t* r, uint8_t r_size, bool lock = true);
	static int i2c_write_read(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay = 0);
	
protected:
	static unsigned int packetNum;
	static unsigned int errorNum;
	static void print_array(uint8_t* a, uint8_t a_size);
	
private:
	//Mutex for instance/constructor
	static pthread_mutex_t smMutex;
	//Mutex for acquire filedescriptor from wiringPI library		
	static pthread_mutex_t aMutex;
	//Mutex for read and write operations, other threads will hang until this mutex is freed		
	static pthread_mutex_t rwMutex;

	//Array containing filedescriptors for the rpi
	static int fd[128];					

	//Get a file descriptor from the wiringPi library for a slave address	
	static bool attach_fd(uint8_t i2c_address);							
};

#endif

#endif