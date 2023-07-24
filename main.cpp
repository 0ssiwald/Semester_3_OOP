#include <iostream>
using namespace std;
#include "clibrarypool.h"
int main()
{
CLibraryPool LP("data.xml");
cout << LP << endl;
return 0;
}
