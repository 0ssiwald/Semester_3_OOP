#include "parse.h"
#include "caddress.h"


std::ostream &operator<<(std::ostream &ostr, const CAddress &addr) {
   ostr << addr.street << " " << addr.number << "; " << addr.zipcode << " " << addr.town;
   return ostr;
}

void CAddress::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Address>") == std::string::npos) {
         if(s.find("<Street>") != std::string::npos) {
            street = parseLine(s,"<Street>", "</Street>");
         } else if(s.find("<Number>") != std::string::npos) {
            number = parseLine(s,"<Number>", "</Number>");
         } else if(s.find("<Zipcode>") != std::string::npos) {
            zipcode = parseLine(s,"<Zipcode>", "</Zipcode>");
         } else if(s.find("<Town>") != std::string::npos) {
            town = parseLine(s,"<Town>", "</Town>");
         }
      }
   }
}
