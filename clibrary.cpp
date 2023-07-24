#include "parse.h"
#include "clibrary.h"


void CLibrary::print() {
   std::cout << "Buecherei Filiale " << name << std::endl;
   address->print();
   std::cout << std::endl << "Filialleiter: ";
   manager->print();
   std::cout << std::endl << std::endl;
   std::cout << "Es stehen " << media.size() << " Medien zur Verfuegung: " << std::endl;
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
            CEmployee *pM = new CEmployee;
            pM->load(file);
            manager = pM;
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress *pA = new CAddress;
            pA->load(file);
            address = pA;
         } else if(s.find("<Book>") != std::string::npos) {
            CBook *pB = new CBook;
            pB->load(file);
            media.push_back(pB);
         } else if(s.find("<DVD>") != std::string::npos) {
            CDVD *pDVD = new CDVD;
            pDVD->load(file);
            media.push_back(pDVD);
         } else if(s.find("<CD>") != std::string::npos) {
            CCD *pCD = new CCD;
            pCD->load(file);
            media.push_back(pCD);
         } else if(s.find("<Audiobook>") != std::string::npos) {
            CAudiobook *pA = new CAudiobook;
            pA->load(file);
            media.push_back(pA);
         } else if(s.find("<Magazine>") != std::string::npos) {
            CMagazine *pM = new CMagazine;
            pM->load(file);
            media.push_back(pM);
         }
      }
   }
}
