///////////////////////////////////////////////////////////////////////
// Workshop 5													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/14/19                                                ///
/////////////////////////////////////////////////////////////////

#ifndef _345_TAXABLE_H
#define _345_TAXABLE_H

namespace sict {

	class Taxable {

		float taxRate;

	public:

		//one arg constructor
		Taxable(float prescribedTax) {
		
			taxRate = prescribedTax;
		}

		float operator()(float incomingPrice) {
		
			return ((incomingPrice * taxRate) + incomingPrice);
		}

	};

}

#endif