#ifndef CDATE_H_INCLUDED
#define CDATE_H_INCLUDED

#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>

class CDate
{
private:
    int day, month, year;

public:
    // Constructor that sets the date to the current date
    CDate();
    // Cunstructor that sets the date to the given values
    CDate(int d, int m, int y)
        : day(d), month(m), year(y)
    {}

   int getDay() const {
      return day;
    }
   int getMonth() const {
      return month;
    }
   int getYear() const {
      return year;
    }
    void print();
    void load(std::ifstream &);
};

#endif // CDATE_H_INCLUDED
