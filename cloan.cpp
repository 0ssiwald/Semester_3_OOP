#include "cloan.h"

std::ostream &operator<<(std::ostream &ostr, CLoan &loan) {
   ostr << "Ausleihe vom " << loan.loan_date << std::endl;
   ostr << "Rueckgabe bis spaetestens " << loan.return_date << std::endl;
   ostr << *loan.medium << std::endl;
   ostr << "Ausgeliehen von " << loan.customer->getName() << std::endl;
return ostr;
}

sNumbers CLoan::load(std::ifstream &file) {
   std::string s;
   sNumbers Numbers;
   if(file){
      while(std::getline(file, s) && s.find("</Loan>") == std::string::npos) {
         if(s.find("<Signature>") != std::string::npos) {
            Numbers.medium_nr = parseLine(s,"<Signature>", "</Signature>");
         } else if(s.find("<CustomerNr>") != std::string::npos) {
            Numbers.customer_nr = parseLine(s,"<CustomerNr>", "</CustomerNr>");
            //CCustomer C;
           // C.setCustomerNr(parseLine(s,"<CustomerNr>", "</CustomerNr>"));
            //customer = &C;
         } else if(s.find("<LoanDate>") != std::string::npos) {
            CDate d;
            d.load(file);
            loan_date = d;
         } else if(s.find("<LoanDays>") != std::string::npos) {
            int days = stoi(parseLine(s,"<LoanDays>", "</LoanDays>"));
            return_date = loan_date + days;
         }
      }
   }
   return Numbers;
}
