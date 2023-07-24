#include <iomanip>
#include <iostream>
#include "ctime.h"

CTime::CTime() {
   time_t t = time(NULL);
   tm *timePtr = localtime(&t);

   hour = timePtr->tm_hour;
   minute = timePtr->tm_min;
   second = timePtr->tm_sec;
}

void CTime::print() {
   char old = std::cout.fill();
   std::cout << std::setfill('0') << std::setw(2) << hour << "." << std::setw(2) << minute << "." << std::setw(2) << second;
   std::cout << std::setfill(old);
}

