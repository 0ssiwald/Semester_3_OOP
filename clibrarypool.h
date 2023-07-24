#ifndef CLIBRARYPOOL_H_INCLUDED
#define CLIBRARYPOOL_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include "clibrary.h"
#include "cperson.h"

class CLibraryPool {
   std::string name;
   CPerson *boss;
   std::vector<CLibrary*> stores;
   std::vector<CPerson*> costumers;

public:
   CLibraryPool(std::string n, CPerson *b, std::vector<CLibrary*> s, std::vector<CPerson*> c)
      : name(n), boss(b), stores(s), costumers(c)
      {}
   CLibraryPool(std::string n, CPerson *b)
      : name(n), boss(b)
      {}
   void add(CLibrary *store) {
      stores.push_back(store);
   }
   void add(CPerson *costumer) {
      costumers.push_back(costumer);
   }
   void print();
};


#endif // CLIBRARYPOOL_H_INCLUDED
