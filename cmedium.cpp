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
