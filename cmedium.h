#ifndef CMEDIUM_H_INCLUDED
#define CMEDIUM_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "parse.h"
#include "clocation.h"
#include "ctime.h"


class CMedium {
public:
   enum e_status {verfuegbar, ausgeliehen, bestellt, reserviert};

   CMedium(std::string tit, std::string sig, CLocation pl, int rat, e_status sta)
      : title(tit), signature(sig), place(pl), age_rating(rat), status(sta)
      {}
   CMedium() {}
   virtual ~CMedium() {
      std::cout << "Das Medium '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   std::string getStatus();
   virtual void print();
   void parseMedium(std::ifstream &, std::string);

protected:
   std::string title, signature;
   CLocation place;
   int age_rating;
   e_status status;
};

class CPrintedMedium: virtual public CMedium {
protected:
   int pages;
public:
   ~CPrintedMedium() {
      std::cout << "Das Printed-Medium '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   virtual void print();
};

class CCD: virtual public CMedium {
protected:
   std::string artist;
   int number_of_tracks;
public:
   ~CCD() {
   std::cout << "Die CD '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   void load(std::ifstream &);
   void print();
};

class CDVD: public CMedium {
   std::string actors;
   CTime lenght;
public:
   ~CDVD() {
   std::cout << "Die DVD '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   void load(std::ifstream &);
   void print();
};

class CMagazine: public CPrintedMedium {
   std::string designer;
public:
   ~CMagazine() {
   std::cout << "Das Magazin '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   void load(std::ifstream &);
   void print();
};
class CBook: virtual public CPrintedMedium {
protected:
   std::string author;
public:
   ~CBook() {
   std::cout << "Das Buch'" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   void load(std::ifstream &);
   void print();
};

class CAudiobook: public CBook, public CCD {
   int number_of_cds;
public:
   ~CAudiobook() {
   std::cout << "Das Audiobuch '" << title << "' mit der Signatur '" << signature << "' wird vernichtet!" << std::endl;
   }
   void load(std::ifstream &);
   void print();
} ;

#endif // CMEDIUM_H_INCLUDED
