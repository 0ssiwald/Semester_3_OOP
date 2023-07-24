#ifndef CPERSON_H_INCLUDED
#define CPERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include "cdate.h"
#include "caddress.h"

class CPerson{

      std::string name;
      CAddress address;
      CDate birthday;

public:
   CPerson(std::string n, CAddress a, CDate b)
      : name(n), address(a), birthday(b)
      {}
   CPerson()
      {}

   ~CPerson() {
      std::cout << "Die Person '" << name << "' wird vernichtet!\n";
   }

   void print();
   void load(std::ifstream &);
};

#endif
