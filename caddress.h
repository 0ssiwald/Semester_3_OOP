#include <iostream>

#ifndef CADRESS_H_INCLUDED
#define CADRESS_H_INCLUDED

class CAddress {
   string street, number, zipcode, town;
public:
   CAddress(string street, string number,  string zipcode, string town)
      : street(street), number(number), zipcode(zipcode), town(town)
      {}
   void set(string s, string n,  string z, string t) {
      street = s;
      number = n;
      zipcode = z;
      town = t;
   }
/*
   string getStreet() const {
      return street;
   }
   string getNumber() const {
      return number;
   }
   string getZipcode() const{
      return zipcode;
   }
      string getTown() const{
      return town;
   }
*/

   void print() {
      std::cout << street << number << std::endl << zipcode << " " << town;
   }
};

#endif
