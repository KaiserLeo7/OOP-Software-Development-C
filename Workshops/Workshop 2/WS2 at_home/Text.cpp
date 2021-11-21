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
#include <iomanip>
#include <fstream>
#include <string>

namespace sict {

	Text::Text() {
		record = nullptr;
		storedRecords = 0;
	}

	Text::Text(const char* fileName) {

		//take incoming file, open for reading
		std::ifstream file(fileName, std::ios::in);

		//Count the Files
		if (file.is_open()) {

			//create a temp string
			std::string temp;
			storedRecords = 0;

			while (std::getline(file, temp))
				storedRecords++;
		}

		//Allocate Memory
		record = nullptr;
		record = new std::string[storedRecords];

		// Reset
		file.clear();  

		// file position to begining
		file.seekg(0, std::ios_base::beg);

		for (int i = 0; i < storedRecords; i++) {
			getline(file, record[i]);
		}
		file.close();
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

				for (int i = 0; i < storedRecords; i++) {

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
