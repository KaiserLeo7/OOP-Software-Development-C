///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////

#ifndef _OOP345_SALE_H
#define _OOP345_SALE_H

#include "iProduct.h"
#include <vector>

namespace sict {

	class Sale {

		std::vector <iProduct*> prodObject;

	public:

		Sale(const char*);
		void display(std::ostream& os) const;
	};
}

#endif

