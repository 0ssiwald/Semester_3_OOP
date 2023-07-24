#include <iostream>

using namespace std;

#include "cdate.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"

int main()
{
   CLocation L1, L2("Technik", "Computer"); // Technik-Abteilung im Computer-Regal
   CDate Geburtstag(7, 11, 1984);
   CAddress A1("Luxemburger Str.", "10", "D-13351", "Berlin");
   CAddress Adresse("Berliner Str.", "21-23", "10876", "Berlin");
   CPerson Egon("Egon Mustermann", Adresse, Geburtstag);

   cout << "\nKlasse CLocation:" << endl;
   cout << "Standardkonstruktor fuer neue Buecher:    ";     L1.print();   cout << endl;
   cout << "Konstruktor Technik-Abt., Computer-Regal: ";     L2.print();   cout << endl;

   cout << "\nKlasse CAddress:" << endl;
   cout << "Konstruktor Adresse der Beuth Hochschule:\n";    A1.print();   cout << endl;

   cout << "\nKlasse CPerson:" << endl;
   cout << "Konstruktor Egon Mustermann:\n";                 Egon.print(); cout << endl;

   return 0;
}
