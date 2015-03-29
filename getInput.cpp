#include <string>
#include <iostream>

#include "getInput.h"

// This is used to get input from the user.
// pressing the enter key with no arguments saves the time of the night
// pressing a 1 and then enter terminates the program.
std::string GetInput() {
	std::string input;
	getline(std::cin, input); // Gets a String Input
	return input;
}

