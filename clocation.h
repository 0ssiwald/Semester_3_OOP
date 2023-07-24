#ifndef CLOCATION_H_INCLUDED
#define CLOCATION_H_INCLUDED


#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

class CLocation {
   std::string section, rack;

public:
   CLocation()
      : section("Buero"), rack("Fach zum Einsortieren")
      {}
   CLocation(std::string s, std::string r)
      : section(s), rack(r)
      {}

   friend std::ostream &operator<<(std::ostream &, CLocation &);
   void load(std::ifstream &);
};

#endif // CLOCATION_H_INCLUDED
