#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

#include <iostream>
#include <fstream>
#include <ctime>
#include "parse.h"

class CTime
{
private:
    int hour, minute, second;

public:
    // Constructor to get the current time
   CTime();
    // Constructor to set a specific time
   CTime(int h, int m, int s = 0)
      : hour(h), minute(m), second(s) {}
    // Method to print the Time
   void print();

   void load(std::ifstream &file) {
   hour = 0; minute = 0; second = 0;
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("<Time>") == std::string::npos) {
         if(s.find("<Hour>") != std::string::npos) {
            hour = stoi(parseLine(s,"<Hour>", "</Hour>"));
         } else if(s.find("<Minute>") != std::string::npos) {
            minute = stoi(parseLine(s,"<Minute>", "</Minute>"));
         } else if(s.find("<Second>") != std::string::npos) {
            second = stoi(parseLine(s,"<Second>", "</Second>"));
         }
      }
   }
}
};

#endif
