#ifndef CPERSON_H_INCLUDED
#define CPERSON_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "cdate.h"
#include "caddress.h"
#include "cloan.h"
//forward declaration : https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes
class CLoan;

class CPerson {

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
   std::string getName() {
      return name;
   }
   // void print();
   // void load(std::ifstream &);
};

class CCustomer: virtual public CPerson {

protected:
   std::string customerNr;
   std::vector<CLoan*> loans;

public:
   CCustomer(std::string n, CAddress a, CDate b, std::string nr)
      : CPerson(n, a, b), customerNr(nr) {}
   CCustomer() {}
   ~CCustomer();

   std::string getCustomerNr() {
      return customerNr;
   }
   void addLoan(CLoan *L) {
      loans.push_back(L);
   }
   void load(std::ifstream &);
   friend std::ostream &operator<<(std::ostream &, CCustomer &);
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
   friend std::ostream &operator<<(std::ostream &, CEmployee &);
};

#endif
