///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/27/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#include "Station.h"

namespace sict {

	// 1 arg constructor (receoves a reference to an unmodifiable string and passes it to the subObject)
	Station::Station(const std::string& str) : StationItemSet(str) {}

	//query display (receives a reference to an object os and displays the data for its ItemSet)
	void Station::display(std::ostream& os) const {
	
		StationItemSet.display(os, true);
	}
	
	//a modifier fill (fills the last order in the customer order queue, if empty does nothing)
	void Station::fill(std::ostream& os) {
	
		if (!StationCustomerOrder.empty()) {
		
			if (!StationCustomerOrder.back().isFilled()) {

				StationCustomerOrder.back().fillItem(StationItemSet, os);
			}
		}
	}

	//forwarding query getName (returns a reference to the name of the ItemSet sub-object)
	const std::string& Station::getName() const {
	
		return StationItemSet.getName();
	}

	//query hasAnOrderToRelease 
	//(returns the release state of the current object.
	//returns true IF:
	//the station has filled the item request(s) for the customer order at the front of the queue
	//or the station has no items left;
	//otherwise, it returns false.
	//If there are no orders in the queue, returns false)
	bool Station::hasAnOrderToRelease() const {
		
		bool hasAnOrder = false;

		if (StationCustomerOrder.empty()) {

			hasAnOrder = false;
		}
		else {

			if (StationCustomerOrder.front().isItemFilled(StationItemSet.getName()) || StationItemSet.getQuantity() == 0) {

				hasAnOrder = true;
			}
		}

		return hasAnOrder;
	}

	// modifier (decrements the number of items in the ItemSet, increments the serial number for the next item)
	Station& Station::operator--() {
	
		--StationItemSet;
		return *this;
	}

	// modifier (receives an rvalue reference to a customer order
	// and moves it to the back of the stations queue
	// and returns a reference to the current object)
	Station& Station::operator+=(CustomerOrder&& order) {
	
		StationCustomerOrder.push_back(std::move(order));
		return *this;
	}

	// modifier that receives an lvalue reference to a customer order,
	// removes the order at the front of the queue and
	// moves it to the calling function through the papameter list. 
	// This function returns true if the station filled its part of the order; false otherwise.
	// If theres are no orders in the queue, returns false.
	bool Station::pop(CustomerOrder& ready) {
	
		if (!StationCustomerOrder.empty()) {

			ready = std::move(StationCustomerOrder.front());
			StationCustomerOrder.pop_front();

			return ready.isFilled() ? true : false;
		}
		else {
		
			return false;
		}
	
	}
	
	// query (reports the state of the ItemSet object)
	void Station::validate(std::ostream& os) const {
	
		 os << " getName(): "
			<< StationItemSet.getName()
			<< std::endl;

		os	<< " getSerialNumber(): " 
			<< StationItemSet.getSerialNumber()
			<< std::endl;

		os	<< " getQuantity(): "
			<< StationItemSet.getQuantity()
			<< std::endl;
	}

}