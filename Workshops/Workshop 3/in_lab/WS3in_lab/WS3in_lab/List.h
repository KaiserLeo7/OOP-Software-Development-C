//
// Workshop 3
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/29/19
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


}


#endif