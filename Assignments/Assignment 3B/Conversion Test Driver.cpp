//********************************************************
// File Name   : Assignment 3B.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Expression Evaluator
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "SYMBOLTABLE.H"

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
    
	SymbolTable st;
	string	symbolName;
	double  symbolValue;

	st.Add("A",1.1);
	st.Add("B");
	st.Add("C");

	cout << "SymbolTable : " << endl;
	st.MoveFirst();

	for (int iLoop = 0; iLoop < st.Count(); iLoop++)
	{
		
		st.CurrentSymbol(symbolName, symbolValue);
		cout << "Symbol : " << symbolName 
			 << " Value : " << symbolValue
			 << endl;
		st.MoveNext();
	}
	cout << endl;

	st.SetValue("B",2.2);
	st.SetValue("C",3.3);

	cout << "SymbolTable : " << endl;
	st.MoveFirst();

	for (int iLoop = 0; iLoop < st.Count(); iLoop++)
	{
		
		st.CurrentSymbol(symbolName, symbolValue);
		cout << "Symbol : " << symbolName 
			 << " Value : " << symbolValue
			 << endl;
		st.MoveNext();

	}


    return 0;
}

