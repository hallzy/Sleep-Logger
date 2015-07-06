#ifndef __TIME_H_INCLUDED__
#define __TIME_H_INCLUDED__

// Holds all the information for the time that the program was started
class StartTime {
public:
  // Constructor
  StartTime();

  //Setter and getter methods for the four variables defined
  // below as private variables
  void setHour(int);
  int getHour();
  void setMinute(int);
  int getMinute();
  void setSeconds(int);
  int getSeconds();
  void setUnixTime(int);
  int getUnixTime();
private:
  int hour;
  int minute;
  int seconds;
  int unixTime;
};


// Exactly the same as StartTime except thta it holds values for the times
// during the night at which you were woken up
class WakeTime : public StartTime {
public:

private:

};

// Same as the previous two, except that this holds the difference in times from
// the start time to the wake time ( ie. delta time )
class DeltaTime : public StartTime {
public:

private:

};

DeltaTime UpdateDeltaClass(DeltaTime, StartTime);
WakeTime UpdateWakeClass(DeltaTime, StartTime, WakeTime);

#endif

