#ifndef CADRESS_H_INCLUDED
#define CADRESS_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>

class CAddress {
   std::string street, number, zipcode, town;
public:
   CAddress(std::string street, std::string number,  std::string zipcode, std::string town)
      : street(street), number(number), zipcode(zipcode), town(town)
      {}
   CAddress() {}
   void set(std::string s, std::string n,  std::string z, std::string t) {
      street = s;
      number = n;
      zipcode = z;
      town = t;
   }
   friend std::ostream &operator<<(std::ostream &, const CAddress &);

   void load(std::ifstream &);
};

#endif
