#ifndef CLIBRARY_H_INCLUDED
#define CLIBRARY_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"


class CLibrary {
   std::string name;
   CAddress *address;
   CPerson *person;
   std::vector<CMedium*> media;

public:
   CLibrary(std::string n, CAddress *a, CPerson *p, std::vector<CMedium*> m)
      : name(n), address(a), person(p), media(m)
      {}
   CLibrary(std::string n, CAddress *a, CPerson *p)
      : name(n), address(a), person(p)
      {}
   CLibrary()
      {}
   ~CLibrary() {
         delete address;
         delete person;
      }
   void add(CMedium *m) {
      media.push_back(m);
   }

   void print();

   void load(std::ifstream &);
};

#endif // CLIBRARY_H_INCLUDED
