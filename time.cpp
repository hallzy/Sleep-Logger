#include <ctime>

#include "time.h"


// Holds all the information for the time that the program was started
//Constructor, initializes the 4 variables
StartTime::StartTime(){
	// each object gets these, all initialized to zero.
	hour = 0;
	minute = 0;
	seconds = 0;
	unixTime = 0;
}

//The following are all setter and getter methods for each of the
//four variables that are initialized in the constructor
void StartTime::setHour(int x){
	hour = x;
}
int StartTime::getHour(){
	return hour;
}

void StartTime::setMinute(int x){
	minute = x;
}
int StartTime::getMinute(){
	return minute;
}

void StartTime::setSeconds(int x){
	seconds = x;
}
int StartTime::getSeconds(){
	return seconds;
}

void StartTime::setUnixTime(int x){
	unixTime = x;
}
int StartTime::getUnixTime(){
	return unixTime;
}

// Updates the DeltaTime
DeltaTime UpdateDeltaClass(DeltaTime deltaTime, StartTime startTime){
	deltaTime.setUnixTime(time(NULL) - startTime.getUnixTime());

	// If the number of seconds that has passed is greater than
	// or equal to 60...
	if(deltaTime.getUnixTime() >= 60){
		 // set the minutes that have passed
		deltaTime.setMinute(deltaTime.getUnixTime()/60);

		// Now if the number of minutes that have passed is greater
		 // than or equal to 60...
		if(deltaTime.getMinute() >= 60){
			// Set the hours that have passed and...
			deltaTime.setHour(deltaTime.getMinute()/60);
			// reset the number of minutes to 0.
			deltaTime.setMinute(0); //deltaTime.getMinute() - 60);
		}
	}
	// Update the number of seconds.
	// Note that if less than 60 seconds have passed it returns the delta unix time
	// otherwise it finds the difference between the unix time, and the hours and
	// minutes that have already been evaluated. The remaining seconds that are
	// unacounted for are set to the seconds.
	deltaTime.setSeconds(deltaTime.getUnixTime() - ( (deltaTime.getHour()*3600) + deltaTime.getMinute()*60 ) );

	return deltaTime;
}

//updates the wakeTime
WakeTime UpdateWakeClass(DeltaTime deltaTime, StartTime startTime, WakeTime wakeTime){
	// The time woken up is the starting time added to the change in time from then
	// until now, thus...
	wakeTime.setSeconds(deltaTime.getSeconds() + startTime.getSeconds());
	wakeTime.setMinute(deltaTime.getMinute() + startTime.getMinute());
	wakeTime.setHour(deltaTime.getHour() + startTime.getHour());

	// The following covers the casees where the above 3 calculations cause
	// the values to exceed there maximum. For example, you cannot have more than
	// 59 minutes.

	// This stops the seconds from exceeding 59, by reducing the seconds by 60,
	// and adding 1 to the number of minutes.
	if(wakeTime.getSeconds() >= 60){
		wakeTime.setSeconds(wakeTime.getSeconds() - 60);
		wakeTime.setMinute(wakeTime.getMinute() + 1);
	}
	// This stop sthe minutes from exceeding 59, by reducing the minutes by 60,
	// and adding 1 to the number of hours.
	if(wakeTime.getMinute() >= 60){
		wakeTime.setMinute(wakeTime.getMinute() - 60);
		wakeTime.setHour(wakeTime.getHour() + 1);
	}
	// If hours exceed 12, we reset the hours to 1.
	if(wakeTime.getHour() > 12){
		wakeTime.setHour(1);
	}
	return wakeTime;
}
