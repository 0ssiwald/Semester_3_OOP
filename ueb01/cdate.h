#include <iostream>
#include <ctime>

class CDate
{
private:
    int day, month, year;

public:
    // Constructor that sets the date to the current date
    CDate()
    {
        // time gets the current time in secounds since January 1, 1970
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        day = timePtr->tm_mday;
        month = timePtr->tm_mon + 1;
        year = timePtr->tm_year + 1900;
    }
    // Cunstructor that sets the date to the given values
    CDate(int d, int m, int y)
        : day(d), month(m), year(y)
    {}

    // Print method to print the date
    void print()
    {
        printf("%02d:%02d:%02d", day, month, year);
        // std::cout << day << "." << month << "." << year;
        //  cout is output stream
    }
};
