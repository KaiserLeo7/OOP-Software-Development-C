///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/27/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#include "LineManager.h"

namespace sict {

	//5 argument constructor (moves the customer orders to the front of a queue
	//holding the orders waiting to be filled
	//and determines the index of the last station on the line)
	LineManager::LineManager(std::vector<Station*>& newStationAddresses,
							 std::vector<size_t>& nextIndex,
							 std::vector<CustomerOrder>& newPartsOrdered,
								size_t startingIndex, std::ostream& os) {
		////////////////////////////////////////////////////////////////////

		//save the incoming station data
		m_StationAddresses = newStationAddresses;			//vector
		m_StartingIndex = startingIndex;					//size_t
		m_NextIndex = nextIndex;							//vector

		//save the order size
		orderSize = newPartsOrdered.size();					//size_t

		//move the orders into customer orders
		for (int i = orderSize -1; i >= 0; i--) {

			//moving the last order to the back of the first empty queue
			m_AllPartsOrdered.push_back(std::move(newPartsOrdered[i]));
		}

		//places starting index first in queue
		currentStationOrder.push_back(m_StartingIndex);					// .push_back  Adds a new element at the end of the vector

		//for the size of the stations
		for (size_t i = 0; i < m_NextIndex.size(); i++) {

			//push to the current order the rest of the stations 
			currentStationOrder.push_back(m_NextIndex.at(currentStationOrder[i]));		// .at() returns reference to the element present at location n in the vector.
		}

		//saves the last station as last index
		m_LastStationIndex = currentStationOrder.back();				// .back() Returns a reference to the last element in the vector
	}

	//query (receives a reference and displays the completed and incomplete orders)
	void LineManager::display(std::ostream& os) const {
	
		os << "COMPLETED ORDERS" << std::endl;
		for (size_t i = 0; i < completedOrders.size(); i++) {

			completedOrders[i].display(os, true);
		}

		os << std::endl;

		os << "INCOMPLETE ORDERS" << std::endl;
		for (size_t i = 0; i < incompleteOrders.size(); i++) {

			incompleteOrders[i].display(os, true);
		}
	}

	//modifier (receives a reference object
	//IF there is a customer order on the back of the queue of orders waiting to be filled
	//this function moves it to the starting station on the line.
	//Then executes one fill step of the assembly process at each station on the line if requested
	//once filling step is done at each station, function checks if there is a customer order to be released
	//IF there is order to be released, function releases order from the station.
	//IF station is not the last one, moves order to the next station.
	//IF station is last one, moves order to completed or incomplete set.
	//Function return true if all orders have been processed, otherwise false.
	bool LineManager::run(std::ostream& os) {

		//if there are parts in the queue waiting to be filled
		if (!m_AllPartsOrdered.empty()) {

			//move the orders to the starting station
			*m_StationAddresses[m_StartingIndex] += std::move(m_AllPartsOrdered.back());		// .back() Returns a reference to the last element in the vector
			//remove the moved order from the vector
			m_AllPartsOrdered.pop_back();							// .pop_back Removes the last element in the vector
		}

		size_t qty = m_StationAddresses.size();

		//Executes one fill step of the assembly process at each station on the line
		for (size_t i = 0; i < qty; i++) {

			m_StationAddresses[i]->fill(os);
		}

		for (size_t i = 0; i < qty; ++i) {

			CustomerOrder tempOrder;

			if (m_StationAddresses[i]->hasAnOrderToRelease()) {

				if (m_NextIndex[i] != m_LastStationIndex) {

					m_StationAddresses[i]->pop(tempOrder);	//place the last order into a tempOrder

					os << " --> " << tempOrder.getNameProduct()
						<< " moved from " << m_StationAddresses[i]->getName()
						<< " to " << m_StationAddresses[m_NextIndex[i]]->getName()
						<< std::endl;

					*m_StationAddresses[m_NextIndex[i]] += std::move(tempOrder);
				}

				if (m_NextIndex[i] == m_LastStationIndex) {

					m_StationAddresses[i]->pop(tempOrder);	//place the last order into a tempOrder
					ordersProcessed++;

					if (tempOrder.isFilled()) {

						os << " --> " << tempOrder.getNameProduct()
							<< " moved from " << m_StationAddresses[i]->getName()
							<< " to Completed Set"
							<< std::endl;

						completedOrders.push_back(std::move(tempOrder));		//add the temp order into the completed orders
					}
					else {

						os << " --> " << tempOrder.getNameProduct()
							<< " moved from " << m_StationAddresses[i]->getName()
							<< " to Incomplete Set"
							<< std::endl;

						incompleteOrders.push_back(std::move(tempOrder));		//add the temp order into the incomplete orders
					}
				}
			}
		}

		if (ordersProcessed == orderSize) {
			return true;
		}
		else {
			return false;
		}
	}
}
