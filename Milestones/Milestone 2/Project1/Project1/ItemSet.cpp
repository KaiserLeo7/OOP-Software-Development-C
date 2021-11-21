///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#include "ItemSet.h"
#include "Utilities.h"

#include <string>
#include <iomanip>

namespace sict {

	unsigned int ItemSet::width = 0;

	ItemSet::ItemSet() {

		itemName = '\0';
		serialNum = 0;
		numInSet = 0;
		desc = '\0';
	}

	ItemSet::ItemSet(const std::string& str) {

		Utilities utilObj;
		size_t next_pos = 0;
		std::string temp;

		//if string is not empty
		if (!str.empty()) {

			//extractToken
			itemName = utilObj.extractToken(str, next_pos);

			//if next_pos not the end 
			if (next_pos != std::string::npos) {
				//extract next_pos and use stoi to convert to int
				serialNum = stoi(utilObj.extractToken(str, next_pos));
			}

			if (next_pos != std::string::npos) {
				//extract to next_pos and convert to int
				numInSet = stoi(utilObj.extractToken(str, next_pos));
			}

			//extract last string assign as description
			if (next_pos != std::string::npos) {
				desc = utilObj.extractToken(str, next_pos);
			}

			//if width is > FieldWidth then assign width w/ getFieldWidth
			if (width < utilObj.getFieldWidth()) {
				width = utilObj.getFieldWidth();
			}



		} else{
			std::string empty = "String is Empty";
			throw empty;
		}
	}

	const std::string& ItemSet::getName() const {
	
		return itemName;
	}
	
	const unsigned int ItemSet::getSerialNumber() const {
	
		return serialNum;
	}
	
	const unsigned int ItemSet::getQuantity() const {
	
		return numInSet;
	}
	
	ItemSet& ItemSet::operator--() {
	
		numInSet--;
		serialNum++;

		return *this;
	}

	ItemSet::ItemSet(ItemSet&& src) {
	
		if (this != &src) {
			itemName = src.itemName;
			serialNum = src.serialNum;
			numInSet = src.numInSet;
			desc = src.desc;

			src.itemName = '\0';
			src.serialNum = 0;
			src.numInSet = 0;
			src.desc = '\0';
		}
	}

	void ItemSet::display(std::ostream& os, bool full) const {
	

		if (full)
			os << std::left
			<< std::setw(width)
			<< itemName
			<< " ["
			<< std::setw(5)
			<< serialNum
			<< "] Quantity "
			<< std::setw(3)
			<< numInSet
			<< std::right
			<< " Description: "
			<< desc
			<< std::endl;
	}
}