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
		if (course == nullptr) {
		
			//set main course to null
			m_course = nullptr;
		
		}
		else {

			//get the length of the incoming course
			int length = std::strlen(course);

			//allocate memory for length of any course
			m_course = new char[length];

			//for loop copy new course into main course
			//dont forget to set last nullbyte
			for (int i = 0; i < length; i++)
			{
				m_course[i] = course[i];
				m_course[length] = '\0';
			}
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