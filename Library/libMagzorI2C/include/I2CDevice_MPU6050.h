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

#ifndef I2CDEVICE_MPU6050_H
#define I2CDEVICE_MPU6050_H

#include "AbstractI2CDevice.h"
#include <stdint.h>

class I2CDevice_MPU6050: public AbstractI2CDevice{
	private:
		void initDevice();
	
	protected:
		bool write_register(uint8_t _reg, uint8_t _data);
		uint8_t read_register(uint8_t _reg);
		int16_t combine_2byte(uint8_t _upper, uint8_t _lower);
	
	public:
		I2CDevice_MPU6050() : AbstractI2CDevice() {initDevice();};
		I2CDevice_MPU6050(uint8_t i2c_address) : AbstractI2CDevice(i2c_address) {initDevice();};
		
		void setup_default();
		
		bool set_pwr_mode(uint8_t _pwr_mode);
		
		static const uint8_t PWR_MODE_DEFAULT = 0x00;
		static const uint8_t PWR_MODE_PLL_8MHZ = 0x00;
		static const uint8_t PWR_MODE_PLL_X_GYRO = 0x01;
		static const uint8_t PWR_MODE_PLL_Y_GYRO = 0x02;
		static const uint8_t PWR_MODE_PLL_Z_GYRO = 0x03;
		static const uint8_t PWR_MODE_PLL_EXT_32_768KHZ = 0x04;
		static const uint8_t PWR_MODE_PLL_EXT_19_2MHZ = 0x05;
		static const uint8_t PWR_MODE_STOP = 0x07;
		
		bool set_gyro_range(uint8_t _gyro_range);
		
		static const uint8_t GYRO_RANGE_DEFAULT = 0x00;			//  +/- 250degree/s
		static const uint8_t GYRO_RANGE_250 = 0x00;					//  +/- 250degree/s
		static const uint8_t GYRO_RANGE_500 = 0x01;					//  +/- 500degree/s
		static const uint8_t GYRO_RANGE_1000 = 0x02;				//  +/- 1000degree/s
		static const uint8_t GYRO_RANGE_2000 = 0x03;				//  +/- 2000degree/s
		
		bool set_accel_range(uint8_t _accel_range);
		
		static const uint8_t ACCEL_RANGE_DEFAULT = 0x00;		//	+/- 2g
		static const uint8_t ACCEL_RANGE_2G = 0x00;				//	+/- 2g
		static const uint8_t ACCEL_RANGE_4G = 0x08;				//	+/- 4g
		static const uint8_t ACCEL_RANGE_8G = 0x10;				//	+/- 8g
		static const uint8_t ACCEL_RANGE_16G = 0x18;				//	+/- 16g
		
		int16_t get_temperature();
		
		int16_t get_x_gyro();
		int16_t get_y_gyro();
		int16_t get_z_gyro();
		
		int16_t get_x_accel();
		int16_t get_y_accel();
		int16_t get_z_accel();
		
	
};

#endif