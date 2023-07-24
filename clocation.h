#ifndef CLOCATION_H_INCLUDED
#define CLOCATION_H_INCLUDED

#include <iostream>
#include <string>

class CLocation {
   std::string Section, Rack;

public:
   CLocation()
      : Section("Buero"), Rack("Fach zum Einsortieren")
      {}
   CLocation(std::string s, std::string r)
      : Section(s), Rack(r)
      {}

   void print() {
   std::cout << "Abt.: " << Section << "; " << "Regal: " << Rack << ";";
   }
};

#endif // CLOCATION_H_INCLUDED
