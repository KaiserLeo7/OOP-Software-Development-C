//
// Workshop 1
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/16/19
//

#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <cstring>
#include <iostream>

extern int INITIAL;

namespace sict {

	String::String(const char* course) {

		//if incoming course is NULL
		if (course == NULL) {
		
			//set main course to Null byte
			m_course[0] = '\0';
		
		}
		else {
			//copy incoming course into main course up to MAX characters
			//add null byte to end of string
			std::strncpy(m_course, course, MAX);
				m_course[MAX] = '\0';
		}
	}

	void String::display(std::ostream& os) const {
	
		os << m_course;
	}


	std::ostream& operator<<(std::ostream& os, String& c) {
	
		os << INITIAL++ << ": ";

		c.display(os);
		return os;
	}

};