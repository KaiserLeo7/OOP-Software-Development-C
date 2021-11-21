///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/27/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include "ItemSet.h"
#include "CustomerOrder.h"
#include <iostream>
#include <deque>

namespace sict {

	class Station {

		ItemSet StationItemSet;
		std::deque<CustomerOrder> StationCustomerOrder;

	public:
		
		Station(const std::string&);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;

		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;
	};

}

#endif


