#include <iostream>
#include <ctime>

class CTime
{
private:
    int hour, min, sec;

public:
    // Constructor to get the current time
    CTime() {
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        hour = timePtr->tm_hour;
        min = timePtr->tm_min;
        sec = timePtr->tm_sec;
    }
    // Constructor to set a specific time
    CTime(int h, int m, int s = 0) {
        hour = h;
        min = m;
        sec = s;
    }
   void setTime() {
      time_t t = time(NULL);
      tm *timePtr = localtime(&t);

      hour = timePtr->tm_hour;
      min = timePtr->tm_min;
      sec = timePtr->tm_sec;
   }
   void setTime(int h, int m, int s){
      hour = h;
      min = m;
      sec = s;
   }
   int getSec() const {
      return sec;
    }
   int getMin() const {
      return min;
    }
   int getHour() const {
      return hour;
    }
    // Method to print the Time
    void print() {
        printf("%02d:%02d:%02d", hour, min, sec);
        // std::cout << hour << ":" << min << ":" << sec;
    }
};
