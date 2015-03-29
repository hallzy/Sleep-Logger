
#ifndef __FILEOUTPUT_H_INCLUDED__
#define __FILEOUTPUT_H_INCLUDED__

#include "time.h"

// Methods that are used to print information to the file.
class toFile {
public:
	// Prints the top part of the text file
	void PrintTopOfFile(StartTime);
	// Prints the new recorded times on the termninal window, and in the text file
	void PrintTheTimeWhenEnterWasClicked(WakeTime, DeltaTime);
private:

};

#endif

