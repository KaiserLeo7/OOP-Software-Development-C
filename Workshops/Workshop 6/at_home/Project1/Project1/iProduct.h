///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////


#ifndef _OOP345_IPRODUCT_H
#define _OOP345_IPRODUCT_H

#include <iostream>

namespace sict {

	class iProduct {

	public:

		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}

#endif