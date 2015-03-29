#include <iostream>
#include <string>

#include "getInput.h" // GetInput
#include "time.h" // UpdateDeltaClass, and UpdateWakeClass
#include "fileOutput.h" // PrintTheTimeWhenEnterWasClicked

void Record(StartTime startTime, DeltaTime deltaTime, WakeTime wakeTime, toFile fileObj) {
	std::string inputString; // This will help let us know when to print the new information
	std::cout << "Recording... (Hit enter to save a time, or 1+enter to stop)" << std::endl;

	do {
    // Read input to get time to record
		inputString = GetInput();

    // if the input is a 1, exit the program
		if (inputString == "1") {
			std::cout << "Terminating...";
			return;
		}
		else if (inputString.empty()) { // if the string was empty, (ie, enter was pressed
						// only, update the times and print them.
			 // Updates the time that has passed since the program started.
			deltaTime = UpdateDeltaClass(deltaTime, startTime);
			// Updates the time at which the enter button was pressed
			wakeTime = UpdateWakeClass(deltaTime, startTime, wakeTime);

						// In the ToFile Class
			fileObj.PrintTheTimeWhenEnterWasClicked(wakeTime, deltaTime);
		}
	} while(1);
}

