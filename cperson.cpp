#include <iomanip>
#include <iostream>
#include "cperson.h"
#include "parse.h"


void CPerson::print() {
      std::cout << name <<  std::endl;
      address.print();
      std::cout << std::endl << "* ";
      birthday.print();
   }

void CPerson::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Person>") == std::string::npos) {
         if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s,"<Name>", "</Name>");
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress C;
            C.load(file);
            address = C;
         } else if(s.find("<Birthday>") != std::string::npos) {
            CDate D;
            D.load(file);
            birthday = D;
         }
      }
   }
}
