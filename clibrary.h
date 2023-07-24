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
   CEmployee *manager;
   std::vector<CMedium*> media;

public:
   CLibrary(std::string n, CAddress *a, CEmployee *man, std::vector<CMedium*> med)
      : name(n), address(a), manager(man), media(med)
      {}
   CLibrary(std::string n, CAddress *a, CEmployee *m)
      : name(n), address(a), manager(m)
      {}
   CLibrary()
      {}
   ~CLibrary() {
         delete address;
         delete manager;
         for(unsigned int i = 0; i < media.size(); i++)
            delete media[i];
      }
   void add(CMedium *m) {
      media.push_back(m);
   }

   void print();

   void load(std::ifstream &);
};

#endif // CLIBRARY_H_INCLUDED
