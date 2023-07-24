#include <iomanip>
#include <iostream>
#include "cperson.h"
#include "parse.h"

/*
void CPerson::print() {
      std::cout << name <<  std::endl;
      address.print();
      std::cout << std::endl << "* ";
      birthday.print();
   }

void CPerson::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Person>") == std::string::npos) {
         if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s,"<Name>", "</Name>");
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress C;
            C.load(file);
            address = C;
         } else if(s.find("<Birthday>") != std::string::npos) {
            CDate D;
            D.load(file);
            birthday = D;
         }
      }
   }
}
*/

void CCustomer::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Customer>") == std::string::npos) {
         if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s,"<Name>", "</Name>");
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress C;
            C.load(file);
            address = C;
         } else if(s.find("<Birthday>") != std::string::npos) {
            CDate D;
            D.load(file);
            birthday = D;
         } else if(s.find("<CustomerNr>") != std::string::npos) {
            customerNr = parseLine(s,"<CustomerNr>", "</CustomerNr>");
         }
      }
   }
}

std::ostream &operator<<(std::ostream &ostr, CCustomer &cust) {
      ostr << cust.name << " (Kundennr.: " << cust.customerNr << ")" << std::endl;
      ostr << cust.address << std::endl << "* " << cust.birthday;
      return ostr;
}

CCustomer::~CCustomer() {
      std::cout << "Der Kunde '" << name << "' wird vernichtet!" << std::endl;
}

void CEmployee::load(std::ifstream &file) {
   std::string s;
   if(file){
      while(std::getline(file, s) && s.find("</Manager>") == std::string::npos && s.find("</Chairman>") == std::string::npos) {
         if(s.find("<Name>") != std::string::npos) {
            name = parseLine(s,"<Name>", "</Name>");
         } else if(s.find("<Address>") != std::string::npos) {
            CAddress C;
            C.load(file);
            address = C;
         } else if(s.find("<Birthday>") != std::string::npos) {
            CDate D;
            D.load(file);
            birthday = D;
         } else if(s.find("<CustomerNr>") != std::string::npos) {
            customerNr = parseLine(s,"<CustomerNr>", "</CustomerNr>");
         } else if(s.find("<EmployeeNr>") != std::string::npos) {
            employeeNr = parseLine(s,"<EmployeeNr>", "</EmployeeNr>");
         }
      }
   }
}

std::ostream &operator<<(std::ostream &ostr, CEmployee &emp) {
      ostr << emp.name << " (Kundennr.: " << emp.customerNr << " / Personalnr.: " << emp.employeeNr << ")" << std::endl;
      ostr << emp.address << std::endl << "* " << emp.birthday;
      return ostr;
   }

