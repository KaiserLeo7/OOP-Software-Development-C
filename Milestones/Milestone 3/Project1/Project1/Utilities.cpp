///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#include "Utilities.h"

namespace sict {

	char Utilities::delimiter;

	//default constructor (sets to safe empty)
	Utilities::Utilities() {

		FieldWidth = 0;
	}

	//extractToken
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
	
		std::string token;
		if (next_pos <= str.length()) {

			//find delimiter starting from position next_pos + 1
			size_t delPos = str.find(delimiter, next_pos);

			//token length is delimiter position - last start position
			size_t tokenLength = (delPos - next_pos);

			//if token size is > FieldWidth then make FieldWidth token size
			if (token.length() > FieldWidth) {
				setFieldWidth(token.length());
			}

			if (delPos != std::string::npos) {
				//extract the part fo the string starting from next_pos for the length of tokenLength
				token = str.substr(next_pos, tokenLength);

				//next starting point is delimiter position
				next_pos = delPos + 1;
			}
			else {
			
				token = str.substr(next_pos);
				next_pos = str.length() + 1;
			}

			if (token.length() == 0) {

				std::string nextTo = "Adjacent Delimiters || ";
				throw nextTo;
			}
		}
		return token;
	}

	//getDelimiter (returns delimiter)
	const char Utilities::getDelimiter() const {
	
		return delimiter;
	}

	//getfieldWidth (returns FW)
	size_t Utilities::getFieldWidth() const {
	
		return FieldWidth;
	}

	//setDelimiter (assigns incoming value to delimiter)
	void Utilities::setDelimiter(const char d) {
	
		delimiter = d;
	}

	//setFieldWidth (assigns incoming value to FW)
	void Utilities::setFieldWidth(size_t fieldWidth) {

		FieldWidth = fieldWidth;
	}

}
