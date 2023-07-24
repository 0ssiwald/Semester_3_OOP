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
   CEmployee *boss;
   std::vector<CLibrary*> stores;
   std::vector<CCustomer*> costumers;

public:
   CLibraryPool(std::string n, CEmployee *b, std::vector<CLibrary*> s, std::vector<CCustomer*> c)
      : name(n), boss(b), stores(s), costumers(c)
      {}
   CLibraryPool(std::string n, CEmployee *b)
      : name(n), boss(b)
      {}
   // Constructor to read a file
   CLibraryPool(std::string);
   ~CLibraryPool();


   void add(CLibrary *store) {
      stores.push_back(store);
   }
   void add(CCustomer *costumer) {
      costumers.push_back(costumer);
   }
   void print();
};


#endif // CLIBRARYPOOL_H_INCLUDED
