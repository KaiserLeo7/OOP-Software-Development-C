///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////

#ifndef _OOP345_TAXABLEPRODUCT_H
#define _OOP345_TAXABLEPRODUCT_H

#include "iProduct.h"
#include "Product.h"
#include <iomanip>

namespace sict {

	class TaxableProduct : public Product {
		
		int main_prodNum;
		double main_price;
		char main_taxStatus;
		 const double HST = 1.13;
		const double PST = 1.08;
	
public:

		TaxableProduct();
		TaxableProduct(int, double, char);
		double price() const;
		void display(std::ostream&) const;
	};
	iProduct* readRecord(std::ifstream&);
}

#endif
