///////////////////////////////////////////////////////////////////////////
//																	   ///
//			Name: Andriy Ostapovych									  ///
//			ID: 143066181											 ///
//			Milestone 2												///
//			Date: 7/27/19										   ///
//																  ///
////////////////////////////////////////////////////////////////////

#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include "Station.h"
#include "CustomerOrder.h"
#include <vector>
#include <deque>

namespace sict {

	class LineManager {

		std::vector<CustomerOrder> m_AllPartsOrdered;
		size_t orderSize = 0;

		std::vector<Station*> m_StationAddresses;
		std::vector<size_t> m_NextIndex;
		std::vector<size_t> currentStationOrder;

		size_t m_StartingIndex;
		size_t m_LastStationIndex;
		size_t ordersProcessed = 0;

		std::deque<CustomerOrder> completedOrders;
		std::deque<CustomerOrder> incompleteOrders;

	public:

		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};

}

#endif