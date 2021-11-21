//
// Workshop 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/22/19
//

#define _CRT_SECURE_NO_WARNINGS

#include "Text.h"
#include <iostream>
#include <fstream>
#include <string>

namespace sict {

	int Text::storedRecords = 0;

	Text::Text() : record(nullptr) {

	}

	Text::Text(const char* fileName) {

		std::string buffer = {};
		std::ifstream file;

		file.open("Shakespear");

		//Count the Files
		if (file.is_open())
		{
			while (std::getline(file, buffer))
				storedRecords++;
		}

		//Allocate Memory
		record = new std::string[storedRecords];

		int i = 0;
		std::string line = {};

		while (std::getline(file, line))
			record[i] = line;
		
	}

	// Copy Constructor
	Text::Text(const Text& that) {

		*this = that;
	}
	
	//Copy Assignment Operator
	Text& Text::operator=(const Text& that) {

		if (this != &that) {

			record = nullptr;
			
			storedRecords = that.storedRecords;

			if (storedRecords != 0) {
				record = new std::string[storedRecords];

				for (size_t i = 0; i < storedRecords; i++) {

					record[i] = that.record[i];
				}
			}
		}
		return *this;
	}
	
	// Destructor
	Text::~Text() {
	
		delete[] record;
		record = nullptr;

	}
	
	//return the number of records stored
	size_t Text::size() const {
	
		return storedRecords;
	}

}
