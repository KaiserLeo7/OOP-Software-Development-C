///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#include "Notifications.h"
#include <iostream>

namespace sict {

	//default constructor
	Notifications::Notifications() {
	
		//safe empty
		pointToPointers = nullptr;
		maxNumOfAdrs = 0;
		numOfAdrs = 0;
	}
	
	//one argument constructor
	Notifications::Notifications(int maxElements) {

		if (maxElements > 0) {

			//allocate dynamic memory
			pointToPointers = new const Message*[maxElements];
			maxNumOfAdrs = maxElements;
		}
	}

	//copy costructor
	Notifications::Notifications(const Notifications& src) { 
	
		*this = src;
	}

	//copy assignment operator
	Notifications& Notifications::operator=(const Notifications& src) {
	
		if (this != &src) {

			delete[] pointToPointers;

			if (maxNumOfAdrs > 0) {

				//allocate dynamic memory
				pointToPointers = new const Message*[src.maxNumOfAdrs];

				for (int i = 0; i < src.numOfAdrs; i++) {

					pointToPointers[i] = src.pointToPointers[i];
				}

				maxNumOfAdrs = src.maxNumOfAdrs;
				numOfAdrs = src.numOfAdrs;

			}
			else {

				//else place object in a safe empty
				*this = Notifications();
			}
		}
		return *this;
	}
	
	//move constructor
	Notifications::Notifications(Notifications&& src) {
	
		*this = std::move(src);
	}
	
	//move assignment operator
	Notifications& Notifications::operator=(Notifications&& src) {
	
		if (this != &src) {

			maxNumOfAdrs = src.maxNumOfAdrs;
			numOfAdrs = src.numOfAdrs;

			delete[] pointToPointers;

			if (src.pointToPointers != nullptr) {

				pointToPointers = src.pointToPointers;
				src.pointToPointers = nullptr;
			}

			src.maxNumOfAdrs = 0;
			src.numOfAdrs = 0;
			src.pointToPointers = nullptr;
		}
		
		return *this;
	}
	
	
	//+= operator overload
	Notifications& Notifications::operator+=(const Message& msg) {
	
		//if the object is not empty and the object has room
		if (!msg.empty() && numOfAdrs < maxNumOfAdrs) {
		
			//store address
			pointToPointers[numOfAdrs] = &msg;
			++numOfAdrs;
		}

		return *this;
	}
	
	//-= operator overload
	Notifications& Notifications::operator-=(const Message& msg) {
	
		for (int i = 0; i < numOfAdrs; i++) {

			if (pointToPointers[i] == &msg) {
			
				pointToPointers[i] = nullptr;
				numOfAdrs--;

				for (int j = i + 1; j < maxNumOfAdrs; j++) {

					pointToPointers[j - 1] = pointToPointers[j];
				}
			}
		}
		return *this;
	}
	
	//display
	void Notifications::display(std::ostream& os) const {
	
		for (int i = 0; i < numOfAdrs; i++) {

			pointToPointers[i]->display(os);
		}
	}
	
	//size
	size_t Notifications::size() const {
	
		return numOfAdrs;
	}


	//destructor
	Notifications::~Notifications() {

		delete[] pointToPointers;
		pointToPointers = nullptr;
	}


	//ostream operator overload
	std::ostream& operator<<(std::ostream& os, Notifications& content) {
	
		content.display(os);
		return os;
	}
}