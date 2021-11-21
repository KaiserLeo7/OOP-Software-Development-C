///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#include "Utilities.h"
#include "CustomerOrder.h"


namespace sict {

	size_t CustomerOrder::C_FieldWidth;

	CustomerOrder::CustomerOrder() {

		itemInfo = nullptr;
		itemCount = 0;
		custName = '\0';
		prodName = '\0';
		C_FieldWidth = 0;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {

		Utilities getObject;

		size_t startPos = 0;
		size_t startPos2 = 0;
		size_t delPos = 0;

		//assign to custName the length of string from 0 to delimiter
		custName = getObject.extractToken(str, startPos);

		//if width is > FieldWidth then assign width w/ getFieldWidth
		if (C_FieldWidth < getObject.getFieldWidth()) {
			C_FieldWidth = getObject.getFieldWidth();
		}

		prodName = getObject.extractToken(str, startPos);

		std::string str2 = str.substr(startPos, str.length());

		str2 += "|";

		itemCount = std::count(str2.begin(), str2.end(), getObject.getDelimiter());
		itemInfo = new ItemInfo[itemCount];

		if (itemCount > 0) {
			for (size_t i = 0; i < itemCount; i++) {

				//find delimiter from str2
				delPos = str2.find(getObject.getDelimiter(), startPos2);

				//extract from newStr string up to startPos2 and assign to itemInfo incrementing index partName
				itemInfo[i].partName = getObject.extractToken(str2, startPos2);
				startPos2 = delPos+1;
			}
		}
		else {
			throw "!!!No Items Requested!!!";
		}
	}

	CustomerOrder::~CustomerOrder() {

		delete[] itemInfo;
		itemInfo = nullptr;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) {

		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {

		if (this != &src) {

			custName = src.custName;
			prodName = src.prodName;
			itemCount = src.itemCount;
			itemInfo = src.itemInfo;

			src.custName = '\0';
			src.prodName = '\0';
			src.itemCount = 0;
			src.itemInfo = nullptr;
		}

		return *this;
	}


	//Checks each item request. Fills if item is available, and not filled. Reports filling. Decrements item stock.
	//if item request is filled or if the item is out of stock.. Reports other

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {

		//go through all the items counted
		for (size_t i = 0; i < itemCount; ++i) {

			//check is the part name matches incoming item name
			if (itemInfo[i].partName == item.getName()) {

				itemInfo[i].serialNum = item.getSerialNumber();

				//if the request isnt filled and the quantity is over 0
				if (itemInfo[i].filledStatus == false) {

					//assigns the item a serial number
					

					os << "Filled " << custName
						<< " [" << prodName << "]"
						<< "[" << itemInfo[i].partName << "]"
						<< "[" << itemInfo[i].serialNum << "]"
						<< std::endl;

					//change filled status to true
					itemInfo[i].filledStatus = true;

					//decrement stock, increment serialNum
					item.operator--();
				}
				else if (itemInfo[i].filledStatus == true) {

					os << "Unable to fill " << custName
						<< " [" << prodName << "]"
						<< "[" << itemInfo[i].partName << "]"
						<< "[" << itemInfo[i].serialNum << "]"
						<< "already filled"
						<< std::endl;
				}
				else {

					os << "Unable to fill " << custName
						<< " [" << prodName << "]"
						<< "[" << itemInfo[i].partName << "]"
						<< "[" << itemInfo[i].serialNum << "]"
						<< "out of stock"
						<< std::endl;
				}
			}
		}
	}

	bool CustomerOrder::isFilled() const {

		size_t filledCount = 0;

		//go through the items
		for (size_t i = 0; i < itemCount; i++) {

			//check if filled
			if (itemInfo[i].filledStatus == true) {

				//if filled count it
				filledCount++;
			}
		}

		//if item quantity matches filled count then all are filled
		if (itemCount == filledCount) {

			return true;
		}
		else {
			return false;
		}
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {

		bool itemsfilled = true;

		//go through the items
		for (size_t i = 0; i < itemCount; i++) {

			//if the item name matches incoming name
			if (itemInfo[i].partName == item) {

				//check if not filled
				if (itemInfo[i].filledStatus == false) {

					//if any item is not filled switches to false
					itemsfilled = false;
				}
			}
		}
		return itemsfilled;
	}

	std::string CustomerOrder::getNameProduct() const {

		return std::string(custName + " [" + prodName + "]");
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {

		os << std::left
			<< std::setw(C_FieldWidth)
			<< custName
			<< " [" << prodName << "]"
			<< std::endl;

		if (showDetail == false) {

			for (size_t i = 0; i < itemCount; i++) {

				 os << std::setfill(' ')
					<< std::setw(C_FieldWidth +1)
					<< "    " << std::right
					<< itemInfo[i].partName
					<< std::endl;

			}
		}
		else {

			for (size_t i = 0; i < itemCount; i++) {

				os << "[" << itemInfo[i].serialNum << "] "
					<< itemInfo[i].partName << "- "
					<< itemInfo[i].filledStatus << std::endl;
			}
		}
	}


}