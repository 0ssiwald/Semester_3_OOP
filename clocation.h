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

   void print() {
   std::cout << "Abt.: " << section << "; " << "Regal: " << rack << ";";
   }

   void load(std::ifstream &file) {
      std::string s;
      if(file){
         while(std::getline(file, s) && s.find("</Location>") == std::string::npos) {
            if(s.find("<Section>") != std::string::npos) {
               section = parseLine(s,"<Section>", "</Section>");
            } else if(s.find("<Rack>") != std::string::npos) {
               rack = parseLine(s,"<Rack>", "</Rack>");
            }
         }
      }
   }
};

#endif // CLOCATION_H_INCLUDED
