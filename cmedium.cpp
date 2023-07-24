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

std::ostream &operator<<(std::ostream &ostr, CMedium &med) {
   return med.print(ostr);
}

std::ostream & CMedium::print(std::ostream &ostr) {
   ostr << "Titel:        " << title << std::endl;
   ostr << "Signatur:     " << signature << std::endl;
   ostr << "Ort:          " << place << std::endl;
   ostr << "FSK:          " << "freigegeben ab " << age_rating << " Jahren" << std::endl;
   ostr << "Status:       " << getStatus() << std::endl;
   return ostr;
}

void CMedium::parseMedium(std::ifstream &file, std::string s) {
   status = verfuegbar;
   if(s.find("<Title>") != std::string::npos) {
      title = parseLine(s,"<Title>", "</Title>");
   } else if(s.find("<Signatur>") != std::string::npos) {
      signature = parseLine(s,"<Signatur>", "</Signatur>");
   } else if(s.find("<Location>") != std::string::npos) {
      CLocation L;
      L.load(file);
   } else if(s.find("<FSK>") != std::string::npos) {
      age_rating = stoi(parseLine(s,"<FSK>", "</FSK>"));
   //} else if(s.find("<Status>") != std::string::npos) {
    //  int i = stoi(parseLine(s,"<Status>", "</Status>"));
      //status = static_cast<e_status>(i-1);
   }
}


std::ostream & CPrintedMedium::print(std::ostream &ostr) {
   ostr << "Anz. Seiten:  " << pages << std::endl;
   return ostr;
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

std::ostream &operator<<(std::ostream &ostr, CBook &med) {
   return med.print(ostr);
}

std::ostream & CBook::print(std::ostream &ostr) {
   CMedium::print(ostr);
   CPrintedMedium::print(ostr);
   ostr << "Author:       " << author << std::endl;
   return ostr;
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
std::ostream &operator<<(std::ostream &ostr, CCD &med) {
   return med.print(ostr);
}
std::ostream & CCD::print(std::ostream &ostr) {
   CMedium::print(ostr);
   ostr << "Interpret:    " << artist << std::endl;
   ostr << "Anz. Tracks:  " << number_of_tracks << std::endl;
   return ostr;
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

std::ostream &operator<<(std::ostream &ostr, CDVD &med) {
   return med.print(ostr);
}

std::ostream &CDVD::print(std::ostream &ostr){
   CMedium::print(ostr);
   ostr << "Schauspieler: " << actors << std::endl;
   ostr << "Spieldauer:   " << lenght << std::endl;
   return ostr;

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
std::ostream &operator<<(std::ostream &ostr, CMagazine &med) {
   return med.print(ostr);
   //CMedium::print();
}

std::ostream &CMagazine::print(std::ostream &ostr){
   CMedium::print(ostr);
   ostr << "Designer:     " << designer << std::endl;
   ostr << "Anz. Seiten:  " << pages << std::endl;
   return ostr;
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

std::ostream &operator<<(std::ostream &ostr, CAudiobook &med) {
   return med.print(ostr);
}
std::ostream &CAudiobook::print(std::ostream &ostr){
   CMedium::print(ostr);
   ostr << "Interpret:    " << artist << std::endl;
   ostr << "Anz. Tracks:  " << number_of_tracks << std::endl;
   ostr << "Anz. CDs:     " << number_of_cds << std::endl;
   ostr << "Autor:        " << author << std::endl;
   ostr << "Anz. Seiten:  " << pages << std::endl;
   return ostr;
}
