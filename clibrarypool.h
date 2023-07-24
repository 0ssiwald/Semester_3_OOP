#ifndef CLIBRARYPOOL_H_INCLUDED
#define CLIBRARYPOOL_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
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
   // Constructor to read a file
   CLibraryPool(std::string);
   ~CLibraryPool();


   void add(CLibrary *store) {
      stores.push_back(store);
   }
   void add(CPerson *costumer) {
      costumers.push_back(costumer);
   }
   void print();
};


#endif // CLIBRARYPOOL_H_INCLUDED
