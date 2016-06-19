// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FUNCTIONTABLE.H"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// ------ Functions -------

// ------  Main (Driver) ------
int main(void)
{
    
	FunctionTable ft;
	cout << "FunctionTable : " << endl;
	cout << ft;

	cout << "SIN is " 
		 << (ft.IsFunction("SIN") ? "" : "NOT ")
		 << "a function"
		 << " and takes "
 		 << ft.NumberOfParameters("SIN")
		 << " parameter"
		 << endl;

	cout << "SINR is " 
		 << (ft.IsFunction("SINR") ? "" : "NOT ")
		 << "a function"
		 << " and takes "
 		 << ft.NumberOfParameters("SINR")
		 << " parameter"
		 << endl;

    return 0;
}

