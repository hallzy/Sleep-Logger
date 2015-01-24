#include <iostream>
#include <iomanip>
#include <fstream>

#include "time.h"
#include "fileOutput.h"

//Note that the setw, and setfill commands are used to ensure that there are always
// two digits in an increment of time... ie. instead of having 12:2:36 it will print
// 12:02:36

std::ofstream outf("Sleep Log.txt"); // The text File that we will be using
// Methods that are used to print information to the file.

// This method prints the top piece of the file
void toFile::PrintTopOfFile(StartTime start){
	//Output to text file
	outf << "Start Time: " << start.getHour() <<":" << std::setw(2) 
		 << std::setfill('0') << start.getMinute() << ":" << std::setw(2)
		 << std::setfill('0') << start.getSeconds() << std::endl << std::endl
		 << "Recording:" << std::endl
		 << "*****************************************************************"
		 << std::endl << std::endl << "Length of Time:          Time of the Night:"
		 << std::endl << std::endl;
}
//This method prints the new recorded data to the screen and to the file
void toFile::PrintTheTimeWhenEnterWasClicked(WakeTime wake, DeltaTime delta){
	std::cout << "Time of the Night: " << wake.getHour() << ":" << std::setw(2) << std::setfill('0')
		 << wake.getMinute() << ":" << std::setw(2) << std::setfill('0') << wake.getSeconds() << std::endl;
	
	std::cout << "Length of Time: " << delta.getHour() << ":" << std::setw(2) << std::setfill('0')
		 << delta.getMinute() << ":" << std::setw(2) << std::setfill('0') << delta.getSeconds()
		 << std::endl;
	
	outf << delta.getHour() << ":" << std::setw(2) << std::setfill('0') << delta.getMinute()
		 << ":" << std::setw(2) << std::setfill('0') << delta.getSeconds() << "                  " 
		 << wake.getHour() << ":" << std::setw(2) << std::setfill('0') << wake.getMinute() << ":" 
		 << std::setw(2) << std::setfill('0') << wake.getSeconds() << std::endl;
}
