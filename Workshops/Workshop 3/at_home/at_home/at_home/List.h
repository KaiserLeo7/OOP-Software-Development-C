//
// Workshop 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 6/2/19
//


#ifndef _345_LIST_H
#define _345_LIST_H

namespace sict {

	template <class T, int N>
	class List {

		T elementType[N];
		size_t counter = 0;
	public:

		size_t size() const {
		
			return counter;
		}


		const T& operator[](size_t i) const {
		
			return elementType[i];
		}
		
		void operator+=(const T& t) { 
		
			if (counter < N) {
			
				elementType[counter] = t;
				counter++;
			}
		
		}
	};

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {

	public:
	
		V accumulate(const L& label) const {
		
			//Initialize the accumulator object to the initial values
			//create a new instance for each label and get their initial values
			SummableLVPair<L, V> instance;
			V elementListSum = instance.getInitialValue();

			//sum the elements of the given label
			//cast the current object using (*this) to reference to the base class sub-object
			//then call the member funtion
			//call size for counter
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i) {
			
				//if parameter label matches the base label element add them

				if (label == ((List<T, N>&)*this)[i].BaseLabel()) {
				
					elementListSum = ((List<T, N>&)*this)[i].sum(label, elementListSum);
				}
			
			}
		
			return elementListSum;
		}
	
	};
}


#endif