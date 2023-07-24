#include <iostream>
#include <ctime>

class CTime
{
private:
    int hour, minute, second;

public:
    // Constructor to get the current time
    CTime()
    {
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        hour = timePtr->tm_hour;
        minute = timePtr->tm_min;
        second = timePtr->tm_sec;
    }
    // Constructor to set a specific time
    CTime(int h, int m, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }
    // Method to print the Time
    void print()
    {
        printf("%02d:%02d:%02d", hour, minute, second);
        // std::cout << hour << ":" << minute << ":" << second;
    }
};
