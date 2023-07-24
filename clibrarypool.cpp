#include <iostream>
#include "clibrarypool.h"
#include "parse.h"

//#define MAX_LEN 101

std::ostream &operator<<(std::ostream &ostr, const CLibraryPool &l_pool) {
   ostr << l_pool.name << std::endl << "Leitung "<< *l_pool.boss << std::endl;
   ostr << "\nZum Buechereiverband gehoeren " << l_pool.stores.size() << " Filialen:\n" << std::endl;
   for(unsigned int i = 0; i < l_pool.stores.size(); i++)
      ostr << *l_pool.stores[i] << std::endl;
   ostr << std::endl << "Der Buechereiverband hat " << l_pool.costumers.size() << " Kunden:" << std::endl;
   for(unsigned int i = 0; i < l_pool.costumers.size(); i++)
      ostr << std::endl << *l_pool.costumers[i] << std::endl << std::endl;
   ostr << "Folgende " << l_pool.loans.size() << " Medien sind ausgeliehen:" << std::endl;
   for(unsigned int i = 0; i < l_pool.loans.size(); i++)
      ostr << std::endl << *l_pool.loans[i] << std::endl;
   return ostr;
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
         } else if(s.find("<Loan>") != std::string::npos) {
            CLoan *pLoan = new CLoan;
            sNumbers Ids = pLoan->load(file);
            for(unsigned int i = 0; i < costumers.size(); i++) {
               if(Ids.customer_nr == costumers[i]->getCustomerNr()) {
                  pLoan->setCustomer(costumers[i]);
                  costumers[i]->addLoan(pLoan);
               }
            }
            for(unsigned int i = 0; i < stores.size(); i++) {
               for(unsigned int j = 0; j < stores[i]->getMedia().size(); j++) {
                  if(Ids.medium_nr == stores[i]->getMedia()[j]->getSignature()) {
                     pLoan->setMedium(stores[i]->getMedia()[j]);
                     stores[i]->getMedia()[j]->setStatus(1);
                  }
               }
            }
            loans.push_back(pLoan);
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
   for(unsigned int i = 0; i < loans.size(); i++)
      delete loans[i];
}


