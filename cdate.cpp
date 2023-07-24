#include "parse.h"
#include "cdate.h"

CDate::CDate() {
// time gets the current time in secounds since January 1, 1970
   time_t t = time(NULL);
   tm *timePtr = localtime(&t);

   day = timePtr->tm_mday;
   month = timePtr->tm_mon + 1;
   year = timePtr->tm_year + 1900;
}

std::ostream &operator<<(std::ostream &ostr, const CDate &date) {
    char old = ostr.fill();
    ostr << std::setfill('0') << std::setw(2) << date.day << "." << std::setw(2) << date.month << "." << date.year;
    ostr << std::setfill(old);
    return ostr;
}

void CDate::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(s.find("</Date>") == std::string::npos) {
         std::getline(file, s);
         if(s.find("<Day>") != std::string::npos) {
            day = stoi(parseLine(s,"<Day>", "</Day>"));
         } else if(s.find("<Month>") != std::string::npos) {
            month = stoi(parseLine(s,"<Month>", "</Month>"));
         } else if(s.find("<Year>") != std::string::npos) {
            year = stoi(parseLine(s,"<Year>", "</Year>"));
         }
      }
   }
}

// Only works for number < 28
CDate CDate::operator+(int number) {
   int is_leap_year;
   if(year % 4 == 0 && year % 100 == 1)
      is_leap_year = 1;
   else if(year % 400 == 0)
      is_leap_year = 1;
   else
      is_leap_year = 0;

   switch(month){
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10: if(day + number <= 31)
               return CDate(day + number, month, year);
            else
               return CDate(day - 31 + number, month + 1, year);
   case 12: if(day + number <= 31)
               return CDate(day + number, month, year);
            else
               return CDate(day - 31 + number, month, year + 1);
   case 4:
   case 6:
   case 9:
   case 11: if(day + number <= 30)
               return CDate(day + number, month, year);
            else
               return CDate(day - 30 + number, month + 1, year);
   case 2:  if(is_leap_year == 0){
               if(day + number <= 28)
                  return CDate(day + number, month, year);
               else
                  return CDate(day - 28 + number, month + 1, year);
            } else {
               if(day + number <= 29)
                  return CDate(day + number, month, year);
               else
                  return CDate(day - 29 + number, month + 1, year);
            }
   default: return CDate(day + number, month, year);
   }
}
