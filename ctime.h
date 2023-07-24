#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

#include <iostream>
#include <fstream>
#include <ctime>

class CTime
{
private:
    int hour, minute, second;

public:
    // Constructor to get the current time
    CTime();
    // Constructor to set a specific time
    CTime(int h, int m, int s = 0)
      : hour(h), minute(m), second(s)
      {}
    // Method to print the Time
    void print();
};

#endif
