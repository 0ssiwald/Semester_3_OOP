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
   std::cout << "Titel:        " << title << std::endl;
   std::cout << "Signatur:     " << signature << std::endl;
   std::cout << "Ort:          ";
   place.print();
   std::cout << std::endl;
   std::cout << "FSK:          " << "freigegeben ab " << age_rating << " Jahren" << std::endl;
   std::cout << "Status:       " << getStatus();
}

void CMedium::parseMedium(std::ifstream &file, std::string s) {
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
      status = static_cast<e_status>(i-1);
   }
}


void CPrintedMedium::print() {
   std::cout << "Anz. Seiten:  " << pages << std::endl;
}

void CBook::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Book>") == std::string::npos) {
         if(s.find("<Author>") != std::string::npos) {
            author = parseLine(s,"<Author>", "</Author>");
         } else if(s.find("<Pages>") != std::string::npos) {
            pages = stoi(parseLine(s,"<Pages>", "</Pages>"));
         } else
            parseMedium(file, s);
      }
   }
}

void CBook::print() {
   std::cout << "Author:       " << author << std::endl;
   CPrintedMedium::print();
   CMedium::print();
}

void CCD::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</CD>") == std::string::npos) {
         if(s.find("<Interpret>") != std::string::npos) {
            artist = parseLine(s,"<Interpret>", "</Interpret>");
         } else if(s.find("<Tracks>") != std::string::npos) {
            number_of_tracks = stoi(parseLine(s,"<Tracks>", "</Tracks>"));
         } else
            parseMedium(file, s);
      }
   }
}
void CCD::print() {
   std::cout << "Interpret:    " << artist << std::endl;
   std::cout << "Anz. Tracks:  " << number_of_tracks << std::endl;
   CMedium::print();
}

void CDVD::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</DVD>") == std::string::npos) {
         if(s.find("<Actors>") != std::string::npos) {
            actors = parseLine(s,"<Actors>", "</Actors>");
         } else if(s.find("<PlayingTime>") != std::string::npos) {
            CTime T;
            T.load(file);
         } else
            parseMedium(file, s);
      }
   }
}

void CDVD::print() {
   std::cout << "Schauspieler: " << actors << std::endl;
   std::cout << "Spieldauer:   ";
   lenght.print();
   std::cout << std::endl;
   CMedium::print();
}

void CMagazine::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Magazine>") == std::string::npos) {
         if(s.find("<Designer>") != std::string::npos) {
            designer = parseLine(s,"<Designer>", "</Designer>");
         } else if(s.find("<Pages>") != std::string::npos) {
            pages = stoi(parseLine(s,"<Pages>", "</Pages>"));
         } else
            parseMedium(file, s);
      }
   }
}
void CMagazine::print() {
   std::cout << "Designer:     " << designer << std::endl;
   std::cout << "Anz. Seiten:  " << pages << std::endl;
   CMedium::print();
}

void CAudiobook::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Audiobook>") == std::string::npos) {
         if(s.find("<Interpret>") != std::string::npos) {
            artist = parseLine(s,"<Interpret>", "</Interpret>");
         } else if(s.find("<Pages>") != std::string::npos) {
            pages = stoi(parseLine(s,"<Pages>", "</Pages>"));
         } else if(s.find("<countCDs>") != std::string::npos) {
            number_of_cds = stoi(parseLine(s,"<countCDs>", "</countCDs>"));
         } else if(s.find("<Tracks>") != std::string::npos) {
            number_of_tracks = stoi(parseLine(s,"<Tracks>", "</Tracks>"));
         } else if(s.find("<Author>") != std::string::npos) {
            author = parseLine(s,"<Author>", "</Author>");
         } else
            parseMedium(file, s);
      }
   }
}

void CAudiobook::print() {
   std::cout << "Interpret:    " << artist << std::endl;
   std::cout << "Anz. Tracks:  " << number_of_tracks << std::endl;
   std::cout << "Anz. CDs:     " << number_of_cds << std::endl;
   std::cout << "Autor:        " << author << std::endl;
   std::cout << "Anz. Seiten:  " << pages << std::endl;
   CMedium::print();
}
