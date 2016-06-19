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
//#include "STACK.H"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// ------ Functions -------
bool GetExpression(/* OUT   */ string returnExpression);

// ------  Main (Driver) ------
int main(void)
{
   string userExpression;

   while(GetExpression(userExpression))
   {

   }

	


    return 0;
}

bool GetExpression(/* OUT   */ string returnExpression) 
//-------------------------------------------------
// Pre : <none>
// Post: If user enters "Q" (quit)
//          returns false and 
//          returnExpression is empty string ("")
//       else
//          returns true
//          returnExpression contains user entry 
//-------------------------------------------------
{
	string inputLine;
	bool   returnValue = true;
	


	//
	// ---- Prompt user for expressiong string
    //
	cout << endl;
	cout << endl;
	cout << "Please enter an expression or Q to quit" << endl;
	getline(cin,inputLine);
	
	if ((inputLine.length() == 1)  && (inputLine == "Q") || (inputLine == "q"))
	{
		returnExpression = "";
		returnValue = false;
	}
	else
	{
		returnExpression = inputLine;
		returnValue = true;
	}
	
	return (returnValue);
}

