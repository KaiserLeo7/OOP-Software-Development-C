//
// Workshop 1
// 
// Student Name: Andriy Ostapovych
// Student ID# 143066181
// Date 5/17/19
//

#include <iostream>
#include "process.h"
#include "String.h"

int INITIAL = 3;

using namespace sict;

	//argc number of arguments passed, argv the arguments themselves
	int main(int argc, char *argv[]) {
		std::cout << "Command Line : ";

		//echo the set of arguments to standard output, single space between
		//so long as i is less then the argc passed, output argv 
		for (int i = 0; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;

		//error message and return 1 if no string was entered 
		//argc 2, 1 for argument and one for program name
		if (argc < 2) {
			std::cout << "***Insufficient number of arguments***" << std::endl;
			return 1;
		}

		//for each string call the process function passing it the address of the string
		for (int i = 1; i < argc; i++)
			sict::process(argv[i]);
		 

		return 0;
	}


