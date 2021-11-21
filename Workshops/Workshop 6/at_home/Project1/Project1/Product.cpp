///////////////////////////////////////////////////////////////////////
// Workshop 6													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 7/1/19                                                 ///
/////////////////////////////////////////////////////////////////


#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

extern int FW;

namespace sict {

	//safe empty
	Product::Product() {
	
		main_prodNum = 0;
		main_pricePreTax = 0;
	}

	// 2 arg constructor (assigns incoming values to main variables)
	Product::Product(int prodNum, double pricePreTax) {

		main_prodNum = prodNum;
		main_pricePreTax = pricePreTax;
	}

	//price (returns price)
	double Product::price() const {
	
		return main_pricePreTax;
	}

	//display (displays the info about the product)
	void Product::display(std::ostream& os) const {
	
		os << std::setw(FW)
			<< main_prodNum
			<< std::setw(FW)
			<< main_pricePreTax
			<< std::endl;
	}

	//readRecord (read a single record, allocates memory, stores info into product object, returns its address)
	iProduct* readRecord(std::ifstream& file) {

		iProduct* tempProduct = nullptr;
		int tempProdNum = 0;
		double tempPrice = 0;
		char tempTax = '\0';
		std::string tempLine = {};

		std::getline(file, tempLine, '\n');

		if (tempLine.length() >= 13) {

			int firstSpacePos = tempLine.find_first_of(' ');

			tempProdNum = std::stoi(tempLine.substr(0, firstSpacePos));
			tempPrice = std::stod(tempLine.substr(firstSpacePos, 6));
			tempTax = tempLine.at(tempLine.length() - 1);
			tempLine.clear();

			tempProduct = new TaxableProduct(tempProdNum, tempPrice, tempTax);
			
		} else {

			tempProdNum = std::stoi(tempLine.substr(0, tempLine.find_first_of(' ')));
			tempPrice = std::stod(tempLine.substr(tempLine.find_first_of(' '), tempLine.length()));
			tempLine.clear();

			tempProduct = new Product(tempProdNum, tempPrice);
		}	

		return tempProduct;
	}

	//ostream (inserts product info into stream)
	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
	
		p.display(os);
		return os;
	}

}