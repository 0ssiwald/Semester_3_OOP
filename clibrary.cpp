#include "parse.h"
#include "clibrary.h"


void CLibrary::print() {
   std::cout << "Buecherei Filiale " << name << std::endl;
   address->print();
   std::cout << std::endl << "Filialleiter: ";
   person->print();
   std::cout << std::endl;
   for(unsigned int i = 0; i < media.size(); i++) {
      std::cout << "\nMedium Nr. " << i+1 << std::endl;
      media[i]->print();
      std::cout << std::endl;
   }
}

void CLibrary::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Library>") == std::string::npos) {
         if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s,"<Name>", "</Name>");
         } else if(s.find("<Manager>") != std::string::npos) {
            CPerson *P = new CPerson;
            P->load(file);
            person = P;
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress *A = new CAddress;
            A->load(file);
            address = A;
         } else if(s.find("<Medium>") != std::string::npos) {
            CMedium *M = new CMedium;
            M->load(file);
            media.push_back(M);
         }
      }
   }
}
