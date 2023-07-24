#ifndef CLOAN_H_INCLUDED
#define CLOAN_H_INCLUDED


#include <fstream>
#include "cperson.h"
#include "cmedium.h"
//forward declaration : https://stackoverflow.com/questions/625799/resolve-build-errors-due-to-circular-dependency-amongst-classes
class CCustomer;


typedef struct {
std::string customer_nr;
std::string medium_nr;
} sNumbers;


class CLoan {

CCustomer *customer;
CMedium *medium;
CDate loan_date, return_date;

public:

CLoan() {}

CCustomer *getCustomer() {
   return customer;
}

void setCustomer(CCustomer *c) {
   customer = c;
}

void setMedium(CMedium *m) {
   medium = m;
}
friend std::ostream &operator<<(std::ostream &, CLoan &);

sNumbers load(std::ifstream &);

};

#endif // CLOAN_H_INCLUDED
