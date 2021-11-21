//
// Workshop 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/29/19
//

#include <iostream>

#ifndef _345_LVPAIR_H
#define _345_LVPAIR_H

namespace sict {

	template <typename L, typename V>
	class LVPair {

		L main_label;
		V main_value;

	public:
		LVPair() {
		
			main_label = '\0';
			main_value = 0;

		}
		
		LVPair(const L& label, const V& value) {
		
			main_label = label;
			main_value = value;
		}
		
		void display(std::ostream& os) const {
		
			os << main_label << " : " << main_value << std::endl;
		}

	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {

		pair.display(os);
		return os;
	}
}

#endif