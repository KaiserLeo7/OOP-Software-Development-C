///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#ifndef SICT_CUSTOMERORDER_LINE_H
#define SICT_CUSTOMERORDER_LINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "ItemSet.h"


namespace sict {

	class CustomerOrder {

		struct ItemInfo {

			std::string partName;
			int serialNum{ 0 };
			bool filledStatus {false};
		};
		
		ItemInfo* itemInfo;

		std::string custName;
		std::string prodName;
		size_t itemCount = 0;
		static size_t C_FieldWidth;

	public:

		CustomerOrder();
		CustomerOrder(const std::string&);
		~CustomerOrder();

		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);

		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;

	};
}

#endif