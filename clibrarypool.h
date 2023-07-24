#ifndef CLIBRARYPOOL_H_INCLUDED
#define CLIBRARYPOOL_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "clibrary.h"
#include "cperson.h"
#include "cloan.h"



class CLibraryPool {
   std::string name;
   CEmployee *boss;
   std::vector<CLibrary*> stores;
   std::vector<CCustomer*> costumers;
   std::vector<CLoan*> loans;

public:
   CLibraryPool(std::string n, CEmployee *b, std::vector<CLibrary*> s, std::vector<CCustomer*> c, std::vector<CLoan*> l)
      : name(n), boss(b), stores(s), costumers(c), loans(l)
      {}
   CLibraryPool(std::string n, CEmployee *b)
      : name(n), boss(b)
      {}
   // Constructor to read a file
   CLibraryPool(std::string);
   ~CLibraryPool();

   friend std::ostream &operator<<(std::ostream &, const CLibraryPool &);

   void add(CLibrary *store) {
      stores.push_back(store);
   }
   void add(CCustomer *costumer) {
      costumers.push_back(costumer);
   }
};


#endif // CLIBRARYPOOL_H_INCLUDED
