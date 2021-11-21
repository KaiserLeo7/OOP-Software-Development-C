///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include "MessagePack.h"
#include <iostream>


namespace sict {

	//constructor
	MessagePack::MessagePack() {
	
		//safe empty
		main_messages = nullptr;
		main_elementsInArray = 0;
	}

	//two argument constructor
	MessagePack::MessagePack(Message** arrayOfMsgs, size_t numOfElements) {
	
		//if positive-valued and address of a valid address
		if (numOfElements > 0 && arrayOfMsgs != nullptr) {
		
			//allocate dynamic memory
			main_messages = new Message[numOfElements];

			for (size_t i = 0; i < numOfElements; i++) {

				//if not empty store objects
				if (!arrayOfMsgs[i]->empty()) {
				
					main_messages[i] = *arrayOfMsgs[i];
					main_elementsInArray = i;
				}
				else {
				
					//else place object in a safe empty
					*arrayOfMsgs[i] = Message();
				}
			}
		}
	}
	
	//copy constructor
	MessagePack::MessagePack(const MessagePack& src) {
	
		*this = src;
	}

	//copy assignment operator
	MessagePack& MessagePack::operator=(const MessagePack& src) {
	
		if (this != &src) {
		
			delete[] main_messages;
			main_elementsInArray = src.main_elementsInArray;

			for (size_t i = 0; i < main_elementsInArray; i++) {

				main_messages[i] = src.main_messages[i];
			}
		}
		return *this;
	}

	//move constructor
	MessagePack::MessagePack(MessagePack&& src) {
	
		*this = std::move(src);
	}

	//move assignment operator
	MessagePack& MessagePack::operator=(MessagePack&& src) {
	
		if (this != &src) {
			
			main_messages = src.main_messages;
			main_elementsInArray = src.main_elementsInArray;

			src.main_messages = nullptr;
			src.main_elementsInArray = 0;
		}
		return *this;
	}


	//display 
	void MessagePack::display(std::ostream& os) const {
	
		for (size_t i = 0; i < main_elementsInArray; i++) {

			main_messages[i].display(os);
		}
	}

	//size
	size_t MessagePack::size() const {
	
		return main_elementsInArray;
	}


	//destructor
	MessagePack::~MessagePack() {

		delete[] main_messages;
		main_messages = nullptr;
	}

	//ostream operator overload
	std::ostream& operator<<(std::ostream& os, MessagePack& content) {

		content.display(os);
		return os;
	}
};

