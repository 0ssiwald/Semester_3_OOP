#include "cmedium.h"


std::string CMedium::getStatus() {
      switch (status) {
         case verfuegbar: return "verfuegbar";
         case ausgeliehen: return "ausgeliehen";
         case bestellt: return "bestellt";
         case reserviert: return "reserviert";
         default: return "unbekannt";
      }
   }
void CMedium::print() {
   std::cout << "Titel:    " << title << std::endl;
   std::cout << "Signatur: " << signature << std::endl;
   std::cout << "Ort:      ";
   place.print();
   std::cout << std::endl;
   std::cout << "FSK:      " << "freigegeben ab " << age_rating << " Jahren" << std::endl;
   std::cout << "Status:   " << getStatus();
}

void CMedium::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Medium>") == std::string::npos) {
         if(s.find("<Title>") != std::string::npos) {
            title = parseLine(s,"<Title>", "</Title>");
         } else if(s.find("<Signatur>") != std::string::npos) {
            signature = parseLine(s,"<Signatur>", "</Signatur>");
         } else if(s.find("<Location>") != std::string::npos) {
            CLocation L;
            L.load(file);
         } else if(s.find("<FSK>") != std::string::npos) {
            age_rating = stoi(parseLine(s,"<FSK>", "</FSK>"));
         } else if(s.find("<Status>") != std::string::npos) {
            int i = stoi(parseLine(s,"<Status>", "</Status>"));
            status = static_cast<e_status>(i-1);  // Best option??????????????
         }
      }
   }
}

