///////////////////////////////////////////////////////////////////////
// Workshop 5													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/14/19                                                ///
/////////////////////////////////////////////////////////////////

#ifndef _345_KVPAIR_H
#define _345_KVPAIR_H

#include <iostream>

extern int fieldWidth;

namespace sict {

	template <typename K, typename V>
	class KVPair {

		K main_key;
		V main_value;

	public:
		
		//default constructor
		KVPair() {
		

		}
		
		//two arg constructor
		KVPair(const K& incomingKey, const V& incomingValue) {
		
			main_key = incomingKey;
			main_value = incomingValue;
		}
		
		//templated display
		template<typename F>
		void display(std::ostream& os, F f) const {
		
			os << std::left;
			os << std::setw(fieldWidth);
			os << main_key;
			os << " : ";
			os << std::setw(fieldWidth);
			os << main_value;
			os << f(main_value);
			os << std::endl;
		}

	};

}

#endif