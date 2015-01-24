#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>

#include "getInput.h" // Contains the toFile class
#include "time.h" // Holds all of the different times, such as StartTime, DeltaTime, and WakeTime
		// Also contains all the update functions
#include "fileOutput.h" // All the methods related to sending information to the text file
#include "record.h" // The part of the program that displays and records the times.


int main() {

	int input; // Temporary holding place for the integer inputs.
	StartTime startTime; // time that the program started
	DeltaTime deltaTime; // difference in time from start to wake
	WakeTime wakeTime; // time woken up at
	toFile fileObj;

	std::cout << "Enter the Current Time (Separate Hours Minutes and Seconds with Spaces): ";
	std::cin >> input;
	startTime.setHour(input); // Hour of start time
	std::cin >> input;
	startTime.setMinute(input);	// Minute of Start Time
	std::cin >> input;
	startTime.setSeconds(input);	// Second of Start Time
	std::cout << std::endl << std::endl;

	startTime.setUnixTime(time(NULL));	//Current unix time

	fileObj.PrintTopOfFile(startTime); // Prints the initial top piece of the text file

	std::cin.ignore();

	Record(startTime, deltaTime, wakeTime, fileObj); // Starts the recording

	return 0;

}































