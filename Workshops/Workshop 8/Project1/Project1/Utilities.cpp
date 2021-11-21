// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); i++) {

			for (size_t j = 0; j < price.size(); j++) {
			
				if (desc[i].code == price[j].code) {

					Product* newObject = new Product(desc[i].desc, price[j].price);

					try {

						newObject->validate();
						priceList += newObject;
						delete newObject;
					} 
					catch (...) {

						std::string negPrice = "*** Negative prices are invalid ***";

						throw negPrice;

					}
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {

		// TODO: Add your code here to build a list of products
		//         using smart pointers

		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++) {

			for (size_t j = 0; j < price.size(); j++) {

				if (desc[i].code == price[j].code) {

					std::unique_ptr<Product> newObject {

						new Product(desc[i].desc, price[j].price) 
					};
				
					try {

						newObject->validate();
						priceList += newObject;
					
					}
					catch (...) {

						std::string negativePrice = "*** Negative prices are invalid ***";
						throw negativePrice;
					}
				}
			}
		}

		return priceList;
	}

}