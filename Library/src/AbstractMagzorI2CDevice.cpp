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


#include "AbstractMagzorI2CDevice.h"
#include "I2C_Data_Converter.h"


AbstractMagzorI2CDevice::AbstractMagzorI2CDevice() {
	alertable = false;
}

AbstractMagzorI2CDevice::AbstractMagzorI2CDevice(uint8_t i2c_address){
	alertable = false;
	this->i2c_address = i2c_address;
}

int AbstractMagzorI2CDevice::write_with_crc(uint8_t* w, uint8_t w_size, uint16_t microsecond_wr_delay){
	return I2C_Interface_CRC::write_with_crc(i2c_address, w, w_size, microsecond_wr_delay);
}

int AbstractMagzorI2CDevice::read_with_crc(uint8_t* r, uint8_t r_size){
	return I2C_Interface_CRC::i2c_read(i2c_address, r, r_size);
}

int AbstractMagzorI2CDevice::write_read_with_crc(uint8_t* w, uint8_t w_size, uint8_t* r, uint8_t r_size, uint16_t microsecond_wr_delay){
	return I2C_Interface_CRC::write_read_with_crc(i2c_address, w, w_size, r, r_size, microsecond_wr_delay);
}

uint16_t AbstractMagzorI2CDevice::get_device_id(){
	uint8_t w[1];
	uint8_t r[2];
	
	w[0] = COMMAND_CODE_GET_DEVICE_ID;
	this->write_read_with_crc(w, 1, r, 2, 10);
	

	return I2C_Data_Converter::get_uint16_t(r, 0);
}

uint16_t AbstractMagzorI2CDevice::get_device_version(){
	uint8_t w[1];
	uint8_t r[2];
	
	w[0] = COMMAND_CODE_GET_DEVICE_VERSION;
	this->write_read_with_crc(w, 1, r, 2, 10);
	
	return I2C_Data_Converter::get_uint16_t(r, 0);
}

void AbstractMagzorI2CDevice::software_reset(){
	uint8_t w[1];
	
	w[0] = COMMAND_CODE_SOFTWARE_RESET;
	this->write(w, 1);
	
	return;
}

bool AbstractMagzorI2CDevice::is_alertable(){
	return alertable; 
}

bool AbstractMagzorI2CDevice::alert(){
	return false;
};
