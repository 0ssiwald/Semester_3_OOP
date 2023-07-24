#include <iomanip>
#include <iostream>
#include "cdate.h"

CDate::CDate() {
// time gets the current time in secounds since January 1, 1970
   time_t t = time(NULL);
   tm *timePtr = localtime(&t);

   day = timePtr->tm_mday;
   month = timePtr->tm_mon + 1;
   year = timePtr->tm_year + 1900;
}

 void CDate::print() {
    char old = std::cout.fill();
    std::cout << std::setfill('0') << std::setw(2) << day << "." << std::setw(2) << month << "." << year;
    std::cout << std::setfill(old);
}
