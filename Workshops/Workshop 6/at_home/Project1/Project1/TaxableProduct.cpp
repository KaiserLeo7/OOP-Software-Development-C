///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////

#include "TaxableProduct.h"
#include <fstream>
#include <istream>
#include <iostream>
#include <string>

extern int FW;

namespace sict {

	// 1 arg constructor (safe empty)
	TaxableProduct::TaxableProduct() {

		main_prodNum = 0;
		main_price = 0;
		main_taxStatus = ' ';
	}

	// 3 arg constructor (assigns incoming values to main variables\)
	TaxableProduct::TaxableProduct(int prodNum, double price, char taxStatus) {

		main_prodNum = prodNum;
		main_price = price;
		main_taxStatus = taxStatus;
	}

	//price 
	double TaxableProduct::price() const {

		if (main_taxStatus == 'H') {

			return main_price * HST;
		}
		else {

			return main_price * PST;
		}
	}

	//display
	void TaxableProduct::display(std::ostream& os) const {

		std::string tempTax;

		if (main_taxStatus == 'H') {

			tempTax = " HST";
		}
		if (main_taxStatus == 'P') {

			tempTax = " PST";
		}

		os << std::setw(FW)
			<< main_prodNum
			<< std::setw(FW)
			<< main_price
			<< tempTax
			<< std::endl;
	}
}