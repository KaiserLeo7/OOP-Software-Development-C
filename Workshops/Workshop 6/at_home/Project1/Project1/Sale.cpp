///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////

#include "Sale.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "TaxableProduct.h"

extern int FW;

namespace sict {

	// 1 arg constructor (receives address of string, opens file, read 1 record, moves record into container, keeps reading until end)
	Sale::Sale(const char* file) {

		std::ifstream inFile;
		inFile.open(file);

		if (inFile.good()) {

			for (int i = 0; i < 6; i++) {

				prodObject.push_back(readRecord(inFile));
			}

			inFile.close();
		}
		else {
		
			throw("!!!Cannot Open File!!!");
		}
	}

	//display (displays products that make up sale and total price into format)
	void Sale::display(std::ostream & os) const {

		double total = 0;

		os  << std::setw(FW)
		    << "\nProduct No" 
		    << std::setw(FW)
		    << "Cost" 
		    << std::endl;

		for (int i = 0; i < prodObject.size(); i++) {
		
			os  << std::right
				<< std::setw(FW)
				<< std::fixed
				<< std::setprecision(2);
			
			prodObject[i]->display(os);

			total += prodObject[i]->price();
		}

		os  << std::right
			<< std::setw(FW)
			<< "Total" 
			<< std::setw(FW)
			<< total
			<< std::endl;
	}

}