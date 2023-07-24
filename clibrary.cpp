#include "clibrary.h"


void CLibrary::print() {
   std::cout << "Buecherei Filiale " << name << std::endl;
   adress.print();
   std::cout << std::endl << "Filialleiter: ";
   person->print();
   std::cout << std::endl;
   for(unsigned int i = 0; i < media.size(); i++) {
      std::cout << "\nMedium Nr. " << i+1 << std::endl;
      media[i]->print();
      std::cout << std::endl;
   }
}
