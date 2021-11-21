//
// Workshop 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/22/19
//

#define _CRT_SECURE_NO_WARNINGS

#include "Timekeeper.h"
#include <iostream>
#include <iomanip>

namespace sict {

	Timekeeper::Timekeeper() {}

	void Timekeeper::start() {
	
		startTime = std::chrono::steady_clock::now();
	}
	
	void Timekeeper::stop() {
	
		endTime = std::chrono::steady_clock::now();
	}
	
	//receives the address of a C-style null terminated string
	void Timekeeper::recordEvent(const char* msg) {
	
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

		//copies address of the description into record
		//calculates duration of event and copies it into record
		//copies the address of the string containing descption of the units of time into record  ///////
		//increments the instance variable storedRecords
		for (int i = 0; i < MAX_RECORDS; i++) {

			records[i].message = msg;
			records[i].duration = ms;
			records[i].units = " seconds";
			storedRecords++;

		}
	}
	
	std::ostream& Timekeeper::report(std::ostream& os) const {
	
		os << "\nExecution Times:\n"; 

		for (int i = 0; i < storedRecords; i++) {

			 os << records[i].message << ' ' << std::setw(5) 
				<< records[i].duration.count() / 1000000
				<< records[i].units
				<< std::endl;

		}
	}

};