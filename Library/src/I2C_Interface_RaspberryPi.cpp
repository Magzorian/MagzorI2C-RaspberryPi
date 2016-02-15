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


#include "I2C_Interface_RaspberryPi.h"

int I2C_Interface::fd[128];
pthread_mutex_t I2C_Interface::smMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t I2C_Interface::aMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t I2C_Interface::rwMutex = PTHREAD_MUTEX_INITIALIZER;
unsigned int I2C_Interface::packetNum = 0;
unsigned int I2C_Interface::errorNum = 0;


//Must be called in order to initialize the file descriptors
void I2C_Interface::init() {
	for (int i = 0; i < 128; i++) {
		fd[i] = -1;
	}
}

bool I2C_Interface::attach_fd(uint8_t i2c_address) {
	if ((0 <= i2c_address) & (i2c_address < 128)) {
		//Lock mutex for address acquire
		pthread_mutex_lock(&aMutex);
		
		//Grab fd from wiringPi
		fd[i2c_address] = wiringPiI2CSetup(i2c_address);
		
		//Unlock mutex for address acquire
		pthread_mutex_unlock(&aMutex);

		if (fd[i2c_address] == -1) {
			if (MLogger::is_error_enabled()) {
				printf("Couldn't get device %u fd.\n", i2c_address);
			}
			return true;
		} else {
			if (MLogger::is_info_enabled()) {
				printf("Got device %u fd.\n", i2c_address);
			}
			return false;
		}
	}
	else {
		if (MLogger::is_error_enabled()) {
			printf("Address %u is out of I2C range.\n", i2c_address);
		}
		return false;
	}
}

int I2C_Interface::i2c_write(uint8_t i2c_address, uint8_t* w, uint8_t w_size, bool lock) {
	//Lock readwrite mutex
	if (lock) {
		pthread_mutex_lock(&rwMutex);
	}
	packetNum++;

	if (fd[i2c_address] == -1) {
		attach_fd(i2c_address);
	}

	//Print packet out
	if (MLogger::is_info_enabled()) {
		printf("Write(0x%02x) P#%u: ", i2c_address, packetNum);
		I2C_Interface::print_array(w, w_size);
		printf("\n");
	}
	int ret = write(fd[i2c_address], w, w_size);

	//Unlock readwrite mutex
	if (lock) {
		pthread_mutex_unlock(&rwMutex);
	}
	return ret; //Returns the number of bytes written
}

int I2C_Interface::i2c_read(uint8_t i2c_address, uint8_t* r, uint8_t r_size, bool lock) {
	//Lock readwrite mutex
	if (lock) {
		pthread_mutex_lock(&rwMutex);
	}
	packetNum++;

	if (fd[i2c_address] == -1) {
		attach_fd(i2c_address);
	}

	int ret = read(fd[i2c_address], r, r_size);

	if (MLogger::is_info_enabled()) {
		printf("Read (0x%02x) P#%u: ", i2c_address, packetNum);
		I2C_Interface::print_array(r, r_size);
		printf("\n");
	}

	//Unlock readwrite mutex
	if (lock) {
		pthread_mutex_unlock(&rwMutex);
	}

	return ret; //Returns the number of bytes read
}

int I2C_Interface::i2c_write_read(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay) {
	//Lock readwrite mutex
	pthread_mutex_lock(&rwMutex); 

	if (fd[i2c_address] == -1) {
		attach_fd(i2c_address);
	}

	I2C_Interface::i2c_write(i2c_address, w, w_size, false);
	usleep(microsecond_wr_delay);
	I2C_Interface::i2c_read(i2c_address, r, r_size, false);

	//Unlock readwrite mutex
	pthread_mutex_unlock(&rwMutex);

	return 0;
}

void I2C_Interface::print_array(uint8_t* a, uint8_t a_size) {
	for (int i = 0; i < a_size; i++) {
		printf("0x%02x ", a[i]);
	}
}
