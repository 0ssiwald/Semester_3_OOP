#include <iostream>
using namespace std;
#include "clibrarypool.h"

int main() {
   CLibraryPool LP("data.xml");
   LP.print();
   cout << endl;
   return 0;
}
