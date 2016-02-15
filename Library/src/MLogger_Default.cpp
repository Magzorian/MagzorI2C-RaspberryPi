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

#include "MLogger_Default.h"

bool MLogger::debug_enabled = false;
bool MLogger::error_enabled = true;
bool MLogger::fatal_enabled = true;
bool MLogger::info_enabled = false;
bool MLogger::trace_enabled = false;
bool MLogger::warn_enabled = false;

void MLogger::debug(const std::string& message){
	if(debug_enabled){
		MLogger::print(message);
	}
}

void MLogger::error(const std::string& message){
	if(error_enabled){
		MLogger::print(message);
	}
	
}
void MLogger::fatal(const std::string& message){
	if(fatal_enabled){
		MLogger::print(message);
	}	
}
void MLogger::info(const std::string& message){
	if(info_enabled){
		MLogger::print(message);
	}	
}
void MLogger::trace(const std::string& message){
	if(trace_enabled){
		MLogger::print(message);
	}
}
void MLogger::warn(const std::string& message){
	if(warn_enabled){
		MLogger::print(message);
	}
}

bool MLogger::is_debug_enabled(){
	return debug_enabled;
}
bool MLogger::is_error_enabled(){
	return error_enabled;
}
bool MLogger::is_fatal_enabled(){
	return fatal_enabled;
}
bool MLogger::is_info_enabled(){
	return info_enabled;
}
bool MLogger::is_trace_enabled(){
	return trace_enabled;
}
bool MLogger::is_warn_enabled(){
	return warn_enabled;
}

void MLogger::set_debug_enabled(bool b){
	debug_enabled = b;
}

void MLogger::set_error_enabled(bool b){
	error_enabled = b;
}

void MLogger::set_fatal_enabled(bool b){
	fatal_enabled = b;
}

void MLogger::set_info_enabled(bool b){
	info_enabled = b;
}

void MLogger::set_trace_enabled(bool b){
	trace_enabled = b;
}

void MLogger::set_warn_enabled(bool b){
	warn_enabled = b;
}

void MLogger::set_all_enabled(){
	MLogger::debug_enabled = true;
	MLogger::error_enabled = true;
	MLogger::fatal_enabled = true;
	MLogger::info_enabled = true;
	MLogger::trace_enabled = true;
	MLogger::warn_enabled = true;	
}

void MLogger::set_all_disabled(){
	MLogger::debug_enabled = false;
	MLogger::error_enabled = false;
	MLogger::fatal_enabled = false;
	MLogger::info_enabled = false;
	MLogger::trace_enabled = false;
	MLogger::warn_enabled = false;
}

bool MLogger::print(const std::string& message){
	printf(message.c_str());
	return true;
}

bool MLogger::write(const std::string& message){
	return false;
}
