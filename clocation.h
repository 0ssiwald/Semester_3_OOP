#ifndef CLOCATION_H_INCLUDED
#define CLOCATION_H_INCLUDED

#include <iostream>

class CLocation {
   string Section, Rack;

public:
   CLocation()
      : Section("Buero"), Rack("Fach zum Einsortieren")
      {}
   CLocation(string s, string r)
      : Section(s), Rack(r)
      {}

   void print() {
   std::cout << "Abt.: " << Section << "; " << "Regal: " << Rack << ";";
   }

};

#endif // CLOCATION_H_INCLUDED
