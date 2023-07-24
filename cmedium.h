#ifndef CMEDIUM_H_INCLUDED
#define CMEDIUM_H_INCLUDED

#include <iostream>
#include <string>
#include "clocation.h"


class CMedium {
public:
   enum e_status {verfuegbar, ausgeliehen, bestellt, reserviert};

   CMedium(std::string tit, std::string sig, CLocation pl, int rat, e_status sta)
      : title(tit), signature(sig), place(pl), age_rating(rat), status(sta)
      {}
   ~CMedium() {
      std::cout << "Das Medium '" << title << "' wird vernichtet!\n";
   }
   std::string getStatus();
   void print();

protected:
   std::string title, signature;
   CLocation place;
   int age_rating;
   e_status status;
};

#endif // CMEDIUM_H_INCLUDED
