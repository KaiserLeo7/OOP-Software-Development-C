//
// Workshop 2
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/22/19
//

#ifndef _345_TEXT_H
#define _345_TEXT_H

#include <string>

namespace sict {

	class Text {

		static int storedRecords;

		std::string* record;
	public:

		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};
}

#endif