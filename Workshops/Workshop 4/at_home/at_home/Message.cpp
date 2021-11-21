///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#include "Message.h"
#include <iostream>
#include <string>

namespace sict {

	Message::Message() {

		tweet[0] = '\0';
		userName[0] = '\0';
		tagName[0] = '\0';
	}

	Message::Message(const std::string& fullStr) {

		//using .find_first_of to get the SPACE POSITION and assign VALUE to variable
		size_t firstPos = fullStr.find_first_of(' ');

		//use npos to check if the spacePos was NOT the max position
			//if not then use substr to parse the string using the 0 element and the spacePos values
		if (firstPos != std::string::npos) {
			this->userName = fullStr.substr(0, firstPos);
		}


		if (userName.size() > 0 && userName.size() != fullStr.size()) {
			//using .find to get the @ position then parse to the secondPos for tagName
			size_t tagPos = fullStr.find('@');
		
			//npos check making sure the find @ did not return max position
			if (tagPos != std::string::npos) {

				size_t secondPos = fullStr.find(' ', tagPos);
			
				//if there is an @ then parse from the @ to the secondPos to get tagName
				//parse everything after secondPos for the tweet
				this->tagName = fullStr.substr((tagPos + 1), secondPos - tagPos-1);
				this->tweet = fullStr.substr(secondPos + 1, (fullStr.size()-1));
			}
			else {
		
				//if find @ did return max value then it was not present
				//then set the tweet to be from the first space position + 1 till the end of the string
				
				this->tweet = fullStr.substr(firstPos + 1, (fullStr.size()-1));
			}
		}
		else {

			*this = Message();
		}
		
	}

	bool Message::empty() const {

		return (tweet[0] == '\0' && (userName[0] == '\0' || tagName[0] == '\0')) ? true : false;
	}

	void Message::display(std::ostream& os) const {

		if (!empty()) {

			if (!tagName[0] == '\0') {

				os << ">User  : " << this->userName << std::endl;
				os << " Reply : " << this->tagName << std::endl;
				os << " Tweet : " << this->tweet << std::endl;
			}
			else {

				os << ">User  : " << this->userName << std::endl;
				os << " Tweet : " << this->tweet << std::endl;
			}
		}
	}

}