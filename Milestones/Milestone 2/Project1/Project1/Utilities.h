///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////


#ifndef SICT_UTILITIES_LINE_H
#define SICT_UTILITIES_LINE_H

#include<iostream>
#include <string>

namespace sict {

	class Utilities {

		static char delimiter;
		size_t FieldWidth;
		
	public:

		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif