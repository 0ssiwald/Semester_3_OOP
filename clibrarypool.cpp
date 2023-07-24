#include <iostream>
#include "clibrarypool.h"
#include "parse.h"

#define MAX_LEN 101



void CLibraryPool::print() {
   std::cout << name << std::endl << "Leitung ";
   boss->print();
   std::cout << std::endl << "\nZum Buechereiverband gehoeren " << stores.size() << " Filialen:\n" << std::endl;
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

CLibraryPool::CLibraryPool(std::string file_name) {
   std::ifstream file;
   file.open(file_name, std::ios::binary | std::ios::in);

   std::string s;

   if(file) {
      while(std::getline(file, s)) {
         if(s.find("<Chairman>") != std::string::npos) {
            CEmployee *pE = new CEmployee;
            pE->load(file);
            boss = pE;
         } else if(s.find("<Library>") != std::string::npos) {
            CLibrary *pL = new CLibrary;
            pL->load(file);
            stores.push_back(pL);
         } else if(s.find("<Customer>") != std::string::npos) {
            CCustomer *pC = new CCustomer;
            pC->load(file);
            costumers.push_back(pC);
         } else if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s, "<Name>", "</Name>");
         }
      }
      file.close();
   }
}

CLibraryPool::~CLibraryPool() {
   delete boss;
   for(unsigned int i = 0; i < stores.size(); i++)
      delete stores[i];
   for(unsigned int i = 0; i < costumers.size(); i++)
      delete costumers[i];
}
