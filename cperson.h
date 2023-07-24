#ifndef CPERSON_H_INCLUDED
#define CPERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include "cdate.h"
#include "caddress.h"

class CPerson{

protected:
      std::string name;
      CAddress address;
      CDate birthday;

public:
   CPerson(std::string n, CAddress a, CDate b)
      : name(n), address(a), birthday(b) {}
   CPerson() {}

   ~CPerson() {
      std::cout << "Die Person '" << name << "' wird vernichtet!" << std::endl;
   }

   // void print();
   // void load(std::ifstream &);
};

class CCustomer: virtual public CPerson {

protected:
   std::string customerNr;

public:
   CCustomer(std::string n, CAddress a, CDate b, std::string nr)
      : CPerson(n, a, b), customerNr(nr) {}
   CCustomer() {}
   ~CCustomer() {
      std::cout << "Der Kunde '" << name << "' wird vernichtet!" << std::endl;
   }

   void load(std::ifstream &);
   void print();
};

class CEmployee: virtual public CPerson, public CCustomer {

   std::string employeeNr;

public:
   CEmployee(std::string n, CAddress a, CDate b, std::string c_nr, std::string e_nr)
      : CPerson(n, a, b), CCustomer(n, a, b, c_nr), employeeNr(e_nr) {}
   CEmployee() {}
   ~CEmployee() {
      std::cout << "Der Angestellte '" << name << "' wird vernichtet!" << std::endl;
   }

   void load(std::ifstream &);
   void print();
};

#endif
