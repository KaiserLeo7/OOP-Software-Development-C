//
// Workshop 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/22/19
//

#ifndef _345_TIMEKEEPER_H
#define _345_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict {

	const int MAX_RECORDS = 10;

	class Timekeeper {

		int storedRecords;

		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct {

			const char* message;
			const char* units;

			std::chrono::steady_clock::duration duration;

		} records[MAX_RECORDS];

	public:

		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		void report(std::ostream&) const;
	};

};
#endif