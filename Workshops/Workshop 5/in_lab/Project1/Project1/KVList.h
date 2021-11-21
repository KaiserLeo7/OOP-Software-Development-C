///////////////////////////////////////////////////////////////////////
// Workshop 5													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/14/19                                                ///
/////////////////////////////////////////////////////////////////

#ifndef _345_KVLIST_H
#define _345_KVLIST_H

#include <iostream>

namespace sict {

	template <typename L>
	class KVList {

		L* main_list;
		int numOfElements;
		int maxNumOfElements;

	public:

		//default constructor
		KVList() {
		
			L* main_list = nullptr;
			int numOfElements = 0;
			int maxNumOfElements = 0;
		}

		//one arg constructor
		KVList(int n) {
		
			if (n > 0) {
			
				maxNumOfElements = n;
				main_list = new L[n];
			}
			else {
				
				throw "!!!Number of elements received in the constructor is not positive-valued!!!";
			}
		}

		//move constructor
		KVList(KVList&& src) {
		
			if (this != &src) {
			
				if (src.main_list != nullptr) {
				
					main_list = src.main_list;
					numOfElements = src.maxNumOfElements;
					maxNumOfElements = src.maxNumOfElements;
					
					src.main_list = nullptr;
					src.maxNumOfElements = 0;
					src.maxNumOfElements = 0;
				}	
			}
		}

		//destructor
		~KVList() {
		
			delete[]main_list;
			main_list = nullptr;
		}

		//operator overload
		const L& operator[](size_t i) const {
		
			if (i < 0 || i > numOfElements || i > maxNumOfElements) {
			
				throw "!!!Index passed is out-of-bounds!!!";
			}
			return main_list[i];
		}

		//templated display
		template<typename F>
		void display(std::ostream& os, F f) const {
		
			for (int i = 0; i < numOfElements; i++) {

				main_list[i].display(os, f);
			}
		}
		
		//push_back
		void push_back(const L& l) {
		
			if (numOfElements < maxNumOfElements) {
				
				main_list[numOfElements++] = l;
			}
		}

		//disable copy, move assignment operator and copy constructor
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
	};
}

#endif