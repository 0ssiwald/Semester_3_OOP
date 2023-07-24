#include "clocation.h"
#include "parse.h"

std::ostream &operator<<(std::ostream &ostr, CLocation &loc) {
   std::cout << "Abt.: " << loc.section << "; " << "Regal: " << loc.rack << ";";
   }

void CLocation::load(std::ifstream &file) {
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

