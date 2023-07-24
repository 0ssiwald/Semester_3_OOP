#include <iostream>
#include "clibrarypool.h"

void CLibraryPool::print() {
      std::cout << name << std::endl << "Leitung ";
      boss->print();
      std::cout << std::endl << "Zum Buechereiverband gehoeren " << stores.size() << " Filialen:\n" << std::endl;
      for(unsigned int i = 0; i < stores.size(); i++) {
         stores[i]->print();
         std::cout << std::endl;
      }
      std::cout << std::endl << "Der Buechereiverband hat " << costumers.size() << " Kunden:" << std::endl;
      for(unsigned int i = 0; i < costumers.size(); i++) {
         std::cout << std::endl;
         costumers[i]->print();
         std::cout << std::endl;
      }
   }
