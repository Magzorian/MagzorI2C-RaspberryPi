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

//References:
//http://www.sainsmart.com/zen/documents/20-011-926/MPU-6050/GY521mpu-6050/code/Arduino/MPU6050/MPU6050.cpp
//MPU-6050 Three-Axis Accelerometer and Gyro Simplified User Manual by Ryan L.
#include "I2CDevice_MPU6050.h"

static const uint8_t PWR_MODE = 0x6B;
static const uint8_t GYRO_CONFIG = 0x1B;
static const uint8_t ACCEL_CONFIG = 0x1C;

static const uint8_t ACCEL_X_H = 0x3B;
static const uint8_t ACCEL_X_L = 0x3C;
static const uint8_t ACCEL_Y_H = 0x3D;
static const uint8_t ACCEL_Y_L = 0x3E;
static const uint8_t ACCEL_Z_H = 0x3F;
static const uint8_t ACCEL_Z_L = 0x40;

static const uint8_t TEMP_H = 0x41;
static const uint8_t TEMP_L = 0x42;

static const uint8_t GYRO_X_H = 0x43;
static const uint8_t GYRO_X_L = 0x44;
static const uint8_t GYRO_Y_H = 0x45;
static const uint8_t GYRO_Y_L = 0x46;
static const uint8_t GYRO_Z_H = 0x47;
static const uint8_t GYRO_Z_L = 0x48;


void I2CDevice_MPU6050::initDevice(){
}

bool I2CDevice_MPU6050::write_register(uint8_t _reg, uint8_t _data){
	unsigned char w[2];
	w[0] = _reg;
	w[1] = _data;
	return this->write(w, 2);
}

uint8_t I2CDevice_MPU6050::read_register(uint8_t _reg){
	unsigned char wr[1];
	wr[0] = _reg;
	this->write_read(wr, 1, wr, 1, 0);
	return wr[0];
}

int16_t I2CDevice_MPU6050::combine_2byte(uint8_t _upper, uint8_t _lower){	
	return (((int16_t) _upper) << 8) | _lower;
}

void I2CDevice_MPU6050::setup_default(){
	set_pwr_mode(PWR_MODE_DEFAULT);
	set_gyro_range(GYRO_RANGE_DEFAULT);
	set_accel_range(ACCEL_RANGE_DEFAULT);
}

bool I2CDevice_MPU6050::set_pwr_mode(uint8_t _pwr_mode){
	return this->write_register(PWR_MODE, _pwr_mode);
}

bool I2CDevice_MPU6050::set_gyro_range(uint8_t _gyro_range){
	return this->write_register(GYRO_CONFIG, _gyro_range);
}

bool I2CDevice_MPU6050::set_accel_range(uint8_t _accel_range){
	return this->write_register(ACCEL_CONFIG, _accel_range);
}

int16_t I2CDevice_MPU6050::get_temperature(){
	return combine_2byte(read_register(TEMP_H), read_register(TEMP_L));
}
		
int16_t I2CDevice_MPU6050::get_x_gyro(){
	return combine_2byte(read_register(GYRO_X_H), read_register(GYRO_X_L));
}

int16_t I2CDevice_MPU6050::get_y_gyro(){
	return combine_2byte(read_register(GYRO_Y_H), read_register(GYRO_Y_L));
}

int16_t I2CDevice_MPU6050::get_z_gyro(){
	return combine_2byte(read_register(GYRO_Z_H), read_register(GYRO_Z_L));
}
		
int16_t I2CDevice_MPU6050::get_x_accel(){
	return combine_2byte(read_register(ACCEL_X_H), read_register(ACCEL_X_L));
}

int16_t I2CDevice_MPU6050::get_y_accel(){
	return combine_2byte(read_register(ACCEL_Y_H), read_register(ACCEL_Y_L));
}

int16_t I2CDevice_MPU6050::get_z_accel(){
	return combine_2byte(read_register(ACCEL_Z_H), read_register(ACCEL_Z_L));
}
