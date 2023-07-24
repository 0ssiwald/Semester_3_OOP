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

std::ostream &operator<<(std::ostream &ostr, CTime &time) {
   char old = ostr.fill();
   ostr << std::setfill('0') << std::setw(2) << time.hour << "." << std::setw(2) << time.minute << "." << std::setw(2) << time.second;
   ostr << std::setfill(old);
}

