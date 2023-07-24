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

 void CDate::print() {
    char old = std::cout.fill();
    std::cout << std::setfill('0') << std::setw(2) << day << "." << std::setw(2) << month << "." << year;
    std::cout << std::setfill(old);
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
