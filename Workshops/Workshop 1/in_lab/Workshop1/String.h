//
// Workshop 1
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/17/19
//

#ifndef _345_STRING_H
#define _345_STRING_H
#define MAX 3
#include <iostream>
#include <cstring>


namespace sict {


	class String {

		// MAX including the null terminator
		char m_course[MAX + 1];

	public:
		String(const char*);

		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, String&);
};

#endif