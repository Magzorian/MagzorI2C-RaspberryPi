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


#ifndef ALERTOBSERVER_H
#define ALERTOBSERVER_H

#include "AbstractMagzorI2CDevice.h"

class AlertObserver{
private:
	static const uint8_t MAX_SUBJECTS = 32;
	static AbstractMagzorI2CDevice* subjects[MAX_SUBJECTS];
	static uint8_t subject_count;
	//static bool add_to_array(AbstractMagzorI2CDevice* device);

protected:
	
public:	
	static bool register_subject(AbstractMagzorI2CDevice* device);
	static bool alert();
	
	//static bool unregister_subject(AbstractMagzorI2CDevice* device);
	//static bool unregister_all_subjects();
	
};

#endif
