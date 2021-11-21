//
// Workshop 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 6/2/19
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

		LVPair():main_label{},main_value{} {};


		LVPair(const L& label, const V& value) {
		
			main_label = label;
			main_value = value;
		}
		
		const L& BaseLabel() const { 
		
			return main_label;
		}

		const V& BaseValue() const {
		
			return main_value;
		}


		virtual void display(std::ostream& os) const {
		
			os << this->main_label << ": " << this->main_value << std::endl;
		}

	};

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {

		static V init_value;
		static size_t minWidth;

	public:

		SummableLVPair() {	}

		SummableLVPair(const L& label, const V& v) : LVPair<L,V>(label, v) {
		
			if (minWidth < label.size()) { minWidth = label.size() + 1; }
		}

		const V& getInitialValue() {
		
			return init_value;
		}

		V sum(const L& label, const V& sum) const {
	
			return LVPair<L, V>::BaseValue() + sum;
			
		}

		void display(std::ostream& os) const {

			os.setf(std::ios::left);
			os.width(minWidth);
			os << LVPair<L, V>::BaseLabel() << ": " << LVPair<L, V>::BaseValue() << std::endl;
			os.unsetf(std::ios::left);
		}



	};


	//template declaration initializes field width class variable to 0
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minWidth{ 0 };

	template<>
	std::string SummableLVPair<std::string, std::string>::init_value = "";
	
	template<> 
	int SummableLVPair<std::string, int>::init_value = 0;
	
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const
	{
		return (value + " " + LVPair<std::string, std::string>::BaseValue());
	}


	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {

		pair.display(os);
		return os;
	}
}

#endif