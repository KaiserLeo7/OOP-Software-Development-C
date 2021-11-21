///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 1												///
//			Date: 7/6/19										   ///
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
	
		std::string token = str.substr(next_pos);

		//find delimiter
		size_t delPos = token.find(delimiter);

		//if delimiter is not the end
		if (delPos != std::string::npos) {
			//assign token 0 to delimiter
			token = token.substr(0, delPos);
		
			//check next position
			next_pos += delPos + 1;
			if (token == "") {
				throw "Adjacent Delimiters || ";
			}
		}
		//if token size is > FieldWidth then make FieldWidth token size
		if (token.length() > FieldWidth) {
			setFieldWidth(token.length());
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
