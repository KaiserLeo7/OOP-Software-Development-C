///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#include <iostream>

#ifndef _345_MESSAGE_H
#define _345_MESSAGE_H

namespace sict {

	class Message {

		std::string tweet;
		std::string userName;
		std::string tagName;

	public:

		Message();
		Message(const std::string& fullStr);
		bool empty() const;
		void display(std::ostream& os) const;

	};
}
#endif