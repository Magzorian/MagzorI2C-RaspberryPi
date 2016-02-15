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

#include "AlertObserver.h"

uint8_t AlertObserver::subject_count = 0;
AbstractMagzorI2CDevice* AlertObserver::subjects[MAX_SUBJECTS] = {NULL};

bool AlertObserver::register_subject(AbstractMagzorI2CDevice* device){
	if(subject_count < MAX_SUBJECTS){
		subjects[subject_count] = device;
		subject_count ++;
		return true;
	}
	
	return false;
}

bool AlertObserver::alert(){
	for(uint8_t i = 0; i < subject_count; ++i){ 	//Go through observerList one by one
		if(subjects[i]->alert()){			  				//Check if alert was handled, if it is return
			return true;
		}
	}
	return false;
}


/*
bool AlertObserver::unregister_subject(AbstractMagzorI2CDevice* device){
}

bool AlertObserver::unregister_all_subjects(){
}
*/
