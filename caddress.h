#include <iostream>
#include <string>

#ifndef CADRESS_H_INCLUDED
#define CADRESS_H_INCLUDED

class CAddress {
   std::string street, number, zipcode, town;
public:
   CAddress(std::string street, std::string number,  std::string zipcode, std::string town)
      : street(street), number(number), zipcode(zipcode), town(town)
      {}
   void set(std::string s, std::string n,  std::string z, std::string t) {
      street = s;
      number = n;
      zipcode = z;
      town = t;
   }

   void print() {
      std::cout << street << number << std::endl << zipcode << " " << town;
   }
};

#endif
