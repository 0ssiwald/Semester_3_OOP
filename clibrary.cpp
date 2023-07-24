#include "parse.h"
#include "clibrary.h"


std::ostream &operator<<(std::ostream &ostr, const CLibrary &lib) {
   ostr << "Buecherei Filiale " << lib.name << std::endl;
   ostr << *lib.address << std::endl << "Filialleiter: " << *lib.manager << std::endl << std::endl;
   ostr << "Es stehen " << lib.media.size() << " Medien zur Verfuegung: " << std::endl;
   for(unsigned int i = 0; i < lib.media.size(); i++)
      ostr << "\nMedium Nr. " << i+1 << std::endl << *lib.media[i] << std::endl;
   return ostr;
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



