#include <iostream>

using namespace std;

#include "cdate.h"
#include "clocation.h"
#include "caddress.h"
#include "cperson.h"
#include "cmedium.h"
#include "clibrary.h"
#include "clibrarypool.h"

int main()
{
   CDate D1(17, 11, 1963);


   CLocation L1("Technik", "Computer");
   CLocation L2("Romane", "Krimi");
   CLocation L3("Kinder", "Comics");
   CLocation L4("DVDs", "Horror");

   CAddress A1("Buchallee", "15a", "13315", "Berlin");
   CAddress A2("Schlossstr.", "117", "12077", "Berlin");
   CAddress A3("Muellerstr.", "39", "13309", "Berlin");

   CPerson Leitung("Egon Mustermann", A2, D1);
   CPerson FL1("Peter Mueller", A3, D1);
   CPerson FL2("Erika Mueller", A3, D1);
   CPerson K1("Marion Schulz", A1, D1);
   CPerson K2("Stefan Meier", A2, D1);

   CMedium M1("Programmieren in C", "PC99", L1, 20, CMedium::ausgeliehen);
   CMedium M2("Der Hexer", "He83", L2, 12, CMedium::verfuegbar);
   CMedium M3("Asterix und Obelix", "KC17", L3, 0, CMedium::verfuegbar);
   CMedium M4("Der Werwolf", "WW175", L4, 16, CMedium::ausgeliehen);

   CLibrary LWedding("Wedding", A1, &FL1);
   CLibrary LSteglitz("Steglitz", A2, &FL2);

   CLibraryPool LP("Buechereiverband Berlin", &Leitung);

   LWedding.add(&M1);
   LWedding.add(&M2);

   LSteglitz.add(&M3);
   LSteglitz.add(&M4);

   LP.add(&LWedding);
   LP.add(&LSteglitz);
   LP.add(&K1);
   LP.add(&K2);
   LP.print();

   cout << endl;

   return 0;
}
