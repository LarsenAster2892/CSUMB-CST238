//********************************************************
// File Name   : Midterm 5-30
// Author      : Clarence Mitchell
// Assignment  : Midterm Extra Credit
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Midterm Problem 5-30 Solution 1-15 Test Driver
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

// ------  Includes ------
#include <iostream>
#include <string>
#include "summary.h"
#include "drill.h"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
//
// --- ENUMERATORS -----
// 



// ------ Functions -------
bool		GetContinue(void);
			//-------------------------------------------------
			// Pre : none
			// Post: if users enters 'Y' to continue 
			//          returns TRUE
			//       else
			//          return FALSE
			//-------------------------------------------------


bool		ValidateAnswer(/*	IN	*/ Drill DrillQuestion,
						   /*	IN	*/ int	UserAnswer);
			//-------------------------------------------------
			// Pre : DrillQuestion is assigned
			// Post: Returns True if User Answer is correct
			//       else returns False 
			//-------------------------------------------------



// ------  Main (Driver) ------
int main(void)
{
	Drill	dt;
	Summary st;
	int		UserAnswer;


	cout << endl;
	cout << "------- Welcome to the Computer Assisted Instruction (CAI) Program ------" << endl;
	cout << endl;
	cout << "   This program provides basic math drills  " << endl;
	cout << "   You are presented with math drills  " << endl;
	cout << "   consisting of two whole numbers and one operator " << endl;
	cout << "   you will prompted for the answer " << endl;
	cout << endl;

	while (GetContinue())
	{
		dt.Generate();
		cout << dt;
		

		
		cin >> UserAnswer;
		cin.ignore();
		if (ValidateAnswer(dt, UserAnswer))
		{
			st.IncrementCorrect();
		}
		else
		{
			st.IncrementMissed();
		}

	}
	cout << st << endl;
    return 0;
}

//========================================================================
// Functions
//=======================================================================
bool		GetContinue(void)
//-------------------------------------------------
// Pre : none
// Post: if users enters 'Y' to continue 
//          returns TRUE
//       else
//          return FALSE
//-------------------------------------------------

{
	char ch;
	cout << " Continue (Y/N)? ";
	ch = cin.get();
	return (ch != 'N');
}


bool		ValidateAnswer(/*	IN	*/ Drill DrillQuestion,
						   /*	IN	*/ int	 UserAnswer)
//-------------------------------------------------
// Pre : DrillQuestion is assigned
// Post: Returns True if User Answer is correct
//       else returns False 
//-------------------------------------------------
{
	return (DrillQuestion.Answer() == UserAnswer);
}


