///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#ifndef _345_NOFITY_H
#define _345_NOTIFY_H

#include "Message.h"
#include <iostream>

namespace sict {

	class Notifications	{

		const Message** pointToPointers;
		int maxNumOfAdrs;
		int numOfAdrs;

	public:
		
		Notifications();
		Notifications(int);
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
		~Notifications();
	};
	std::ostream& operator<<(std::ostream&, Notifications&);
}

#endif

