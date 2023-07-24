#include <iostream>
#include "cdate.h"
#include "caddress.h"

#ifndef CPERSON_H_INCLUDED
#define CPERSON_H_INCLUDED

class CPerson{

      string name;
      CAddress address;
      CDate birthday;

public:
   CPerson(string n, CAddress a, CDate b)
      : name(n), address(a), birthday(b)
      {}

   void print() {
      std::cout << name <<  std::endl;
      address.print();
      std::cout << std::endl << "* ";
      birthday.print();
   }
};

#endif
