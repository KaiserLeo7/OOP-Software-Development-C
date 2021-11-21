///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////

#ifndef _OOP345_PRODUCT_H
#define _OOP345_PRODUCT_H

#include "iProduct.h"
#include <iostream>

namespace sict {

	class Product : public iProduct {

		int main_prodNum;
		double main_pricePreTax;

	public:

		Product();
		Product(int, double);
		double price() const;
		void display(std::ostream& os) const;	
	};

	iProduct* readRecord(std::ifstream& file);
}

#endif
