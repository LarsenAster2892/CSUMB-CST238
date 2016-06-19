//********************************************************
// File Name   : Drill.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Member methods for Drill Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************



// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "Drill.H"


//
// ================= Constructors ==========================
//

//
// initailize slot
//
Drill::Drill()
//-------------------------------------------------
// Pre : none
// Post: operand1, operand2 and operator are initialized
//-------------------------------------------------
{
	operand1_ = operand2_ = answer_ = 0;
	operator_ = '\0';
	
}



//
// ================= Accessors ==========================
//
int   Drill::Answer(void)
//-------------------------------------------------
// Pre : none
// Post: returns value of answer
//-------------------------------------------------
{
	return (answer_);
}

int	  Drill::Operand1(void)
//-------------------------------------------------
// Pre : none
// Post: returns value of operand1.
//-------------------------------------------------
{
	return (operand1_);
}

int   Drill::Operand2(void)
//-------------------------------------------------
// Pre : none
// Post: returns value of operand2.
//-------------------------------------------------
{
	return (operand2_);
}

char  Drill::Operator(void)
//-------------------------------------------------
// Pre : none
// Post: returns value of operator
//-------------------------------------------------
{
	return (operator_);
}



//
// ================= Mutators ==========================
//

void  Drill::Generate(void)
//-------------------------------------------------
// Pre : none
// Post: random generated drill question
//       operand1, operand2 and operator are set.
//-------------------------------------------------
{
	operand1_ = 2;
	operand2_ = 6;
	operator_ = '+';
	answer_ = 8;
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
						  /* IN    */ const Drill &d)
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

	os << " How much is " << d.operand1_ << " " 
		                  << d.operator_ << " "
				          << d.operand2_ << " ?";

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
