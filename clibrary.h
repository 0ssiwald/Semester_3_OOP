#ifndef CLIBRARY_H_INCLUDED
#define CLIBRARY_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"


class CLibrary {
   std::string name;
   CAddress adress;
   CPerson *person;
   std::vector<CMedium*> media;

public:
   CLibrary(std::string n, CAddress a, CPerson *p, std::vector<CMedium*> m)
      : name(n), adress(a), person(p), media(m)
      {}
   CLibrary(std::string n, CAddress a, CPerson *p)
      : name(n), adress(a), person(p)
      {}
   void add(CMedium *m) {
      media.push_back(m);
   }

   void print();
};

#endif // CLIBRARY_H_INCLUDED
