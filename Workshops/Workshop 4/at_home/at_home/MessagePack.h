///////////////////////////////////////////////////////////////////////
// Workshop 4													   ///
//																  ///
// Student Name: Andriy Ostapovych                               ///
// Student ID# 143066181                                        ///
// Date 6/11/19                                                ///
/////////////////////////////////////////////////////////////////

#include "Message.h"
#include <iostream>

#ifndef _345_MESSAGEPACK_H
#define _345_MESSAGEPACK_H

namespace sict {

	class MessagePack {

		Message* main_messages;
		size_t main_elementsInArray;

	public:

		MessagePack();
		MessagePack(Message**, size_t);
		MessagePack(const MessagePack&);
		MessagePack& operator=(const MessagePack&);
		MessagePack(MessagePack&&);
		MessagePack& operator=(MessagePack&&);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream&, MessagePack&);
}
#endif