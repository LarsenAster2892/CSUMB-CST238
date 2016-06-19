//********************************************************
// File Name   : Summary.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Member methods for Summary Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************



// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "Summary.H"


//
// ================= Constructors ==========================
//

//
// initailize slot
//
Summary::Summary()
//-------------------------------------------------
// Pre : none
// Post: right and wrong are initialized
//-------------------------------------------------
{
	(*this).Clear();
}



//
// ================= Accessors ==========================
//
//   Get Right answers	
//
int	  Summary::CorrectAnswers(void)
//-------------------------------------------------
// Pre : none
// Post: returns number of correct Answer so far.
//-------------------------------------------------
{
	return (right_);
}
//
//   Get Wrongt answers	
//
int	  Summary::MissedAnswers(void)
//-------------------------------------------------
// Pre : none
// Post: returns number of correct Answer so far.
//-------------------------------------------------
{
	return (wrong_);
}


//
// ================= Mutators ==========================
//

void Summary::Clear(void)
//-------------------------------------------------
// Pre : none
// Post: correct and missed answers are set to zero
//-------------------------------------------------
{
	right_ = wrong_ = 0;
}

void Summary::IncrementCorrect(void)
//-------------------------------------------------
// Pre : none
// Post: correct answers is incremented by 1
//-------------------------------------------------
{
	cout << endl;
	cout << "  You are right.  Great Job!! " << endl;
	cout << endl;

	right_++;
}

void Summary::IncrementMissed(void)
//-------------------------------------------------
// Pre : none
// Post: missed answers is incremented by 1
//-------------------------------------------------
{
	cout << endl;
	cout << "  Incorrect Answer but Good Try! " << endl;
	cout << endl;

	wrong_++;
}


//
// ================= Member Methods ==========================
//

//
// ================= Operators ==========================
//

//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs slot to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const Summary &s)
//----------------------------------------------------
// Pre : os is valid iostream & s is valid slot
// Post: iostream os contains outputted slot
//-------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();
	
	os << endl;
	os << "---- Summary of your drill ----" << endl;
	os << "  Correct Answers: " << s.right_ << endl;
	os << "  Missed  Answers: " << s.wrong_ << endl;
	os << endl;

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
