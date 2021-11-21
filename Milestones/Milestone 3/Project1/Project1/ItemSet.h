///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/12/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include "Utilities.h"
#include <string>

namespace sict {

	class ItemSet {

		std::string itemName;
		unsigned int serialNum;
		unsigned int numInSet;
		std::string desc;
		static unsigned int width;

	public:

		ItemSet();
		ItemSet(const std::string&);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();

		ItemSet(ItemSet&&);
		ItemSet& operator=(ItemSet&&) = delete;
		ItemSet(const ItemSet&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		
		void display(std::ostream& os, bool full) const;
	};

}

#endif