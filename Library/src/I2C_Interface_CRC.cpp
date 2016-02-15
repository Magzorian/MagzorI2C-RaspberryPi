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


#include "I2C_Interface_CRC.h"

int I2C_Interface_CRC::write_with_crc(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint16_t microsecond_wr_delay) {
	//Calculate master_crc(master_data)
	uint8_t master_crc[CRC_BYTES_SIZE];
	//Put crc into the write array
	I2C_CRC::put_crc(w, 0, w_size, master_crc, 0);

	//Create array for reading in slave_CRC(master_data)
	uint8_t read_array[CRC_READ_BYTES_SIZE];
	//Set array to 0
	memset(read_array, 0, sizeof (read_array));

	//Create a new array to for write array to hold the additional master_CRC(master_data)
	uint8_t write_array[w_size + CRC_WRITE_BYTES_SIZE];
	//Copy contents of w (parameter), into new write array
	memcpy(write_array, w, w_size * sizeof (uint8_t));
	//Copy contents of master_crc, into new write array
	memcpy(write_array + w_size * sizeof (uint8_t), master_crc, CRC_WRITE_BYTES_SIZE * sizeof (uint8_t));

	//Keep track of the number of attempts
	unsigned int attempts = 0;

	do {
		//Perform a write read operation
		I2C_Interface::i2c_write_read(i2c_address, write_array, w_size + CRC_WRITE_BYTES_SIZE, read_array, CRC_READ_BYTES_SIZE, microsecond_wr_delay);

		//Check if the CRC passes
		if (I2C_CRC::check_crc_equal(master_crc, read_array)) {
			//return 1 if the crc passes
			return 1;
		}            //CRC check failed, re-attempt the packet
		else {
			//Increment the number of attempts tried
			attempts++;
			//Print message about attempts tried
			MLogger::warn("CRC check failed! Retry attempt...\n");
		}
	} while (attempts < RETRY_ATTEMPTS);
	//Continue loop until attempts are less than retry attempts

	//Print crc error message
	print_crc_error(i2c_address, write_array, w_size + CRC_WRITE_BYTES_SIZE, read_array, CRC_READ_BYTES_SIZE);
	//Return -1 because failed to successfully transmit packet
	return -1;
}

int I2C_Interface_CRC::read_with_crc(uint8_t i2c_address, uint8_t* r, uint8_t r_size) {
	//Return -1 because there is no read with crc function
	return -1;
}

int I2C_Interface_CRC::write_read_with_crc(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay) {
	//Calculate master_crc(master_data)
	uint8_t master_crc[CRC_BYTES_SIZE];
	//Put crc into the write array
	I2C_CRC::put_crc(w, 0, w_size, master_crc, 0);

	//Array to store checksum of slave_crc(slave_data)
	uint8_t slave_crc[CRC_READ_BYTES_SIZE];

	//Create a new array to for write array to hold the additional master_CRC(master_data)
	uint8_t write_array[w_size + CRC_WRITE_BYTES_SIZE];
	//Copy contents of w (parameter), into new write array
	memcpy(write_array, w, w_size * sizeof (uint8_t));
	//Copy contents of master_crc, into new write array
	memcpy(write_array + w_size * sizeof (uint8_t), master_crc, CRC_WRITE_BYTES_SIZE * sizeof (uint8_t));

	//Create a new array for read array to hold the additional slave_crc(master_data) and slave_crc(slave_data)
	uint8_t read_array[CRC_WRITE_BYTES_SIZE + r_size + CRC_READ_BYTES_SIZE];
	//Set array to 0
	memset(read_array, 0, sizeof (read_array));

	//Keep track of the number of attempts
	unsigned int attempts = 0;

	do {
		//Perform a write read operation
		I2C_Interface::i2c_write_read(i2c_address, write_array, w_size + CRC_WRITE_BYTES_SIZE, read_array, CRC_WRITE_BYTES_SIZE + r_size + CRC_READ_BYTES_SIZE, microsecond_wr_delay);

		//Calculate the master_crc(slave_data)
		I2C_CRC::put_crc(read_array, CRC_WRITE_BYTES_SIZE, r_size, slave_crc, 0);

		//Check if write checksum passed or not by comparing slave_CRC(master_data) with master_CRC(master_data)
		bool write_crc_pass = I2C_CRC::check_crc_equal(master_crc, read_array);
		//Check if read data checksum passed or not. by comparing slave_CRC(slave_data) with master_CRC(slave_data)
		bool read_crc_pass = I2C_CRC::check_crc_equal(slave_crc, read_array + (CRC_WRITE_BYTES_SIZE + r_size) * sizeof (uint8_t));

		//Check if write and read crc passed
		if (write_crc_pass && read_crc_pass) {
			//Successfully write read
			//Copy memory over to the r array
			memcpy(r, read_array + CRC_WRITE_BYTES_SIZE, r_size * sizeof (uint8_t));

			//return 1 for successfully write read operation
			return 1;
		}
		else {
			//Increment the number of attempts tried
			attempts++;

			//Overwrite the read array
			memset(r, 0, r_size * sizeof (uint8_t));

			//Print message about attempts tried
			MLogger::warn("CRC check failed! Retry attempt...\n");
		}
	} while (attempts < RETRY_ATTEMPTS);
	//Continue loop until attempts are less than retry attempts

	//Failed to perform the write read operation
	//Overwrite the read array
	memset(r, 0, r_size * sizeof (uint8_t));
	//Print crc error message
	print_crc_error(i2c_address, write_array, w_size + CRC_WRITE_BYTES_SIZE, read_array, CRC_WRITE_BYTES_SIZE + r_size + CRC_READ_BYTES_SIZE);
	//return -1 because failed to write and read succesfully
	return -1;
}

void I2C_Interface_CRC::print_crc_error(uint8_t i2c_address, uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size) {
	if (MLogger::is_error_enabled()) {
		//MLogger::error("WRITING to 0x" + String(i2c_address, HEX) + "(");
		//MLogger::error(String(w_size));
		//MLogger::error(" bytes) :");

		for (uint8_t i = 0; i < w_size; i++) {
			//MLogger::error(String(w[i], HEX));
			//MLogger::error(" ");
		}
		//MLogger::error("\n");

		//MLogger::error("READING from 0x"+ String(i2c_address, HEX) + "(");
		//MLogger::error(String(r_size));
		//MLogger::error(" bytes) :");

		for (uint8_t i = 0; i < r_size; i++) {
			//MLogger::error(String(r[i], HEX));
			//MLogger::error(" ");
		}
		//MLogger::error("\n");

		MLogger::error("CRC check failed! Maximum attempts reached. Giving up...\n");
	}
}
