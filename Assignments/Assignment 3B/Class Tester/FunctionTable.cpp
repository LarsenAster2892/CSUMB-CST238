//********************************************************
// File Name   : FunctionTable.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Class member functions for FunctionTable Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FunctionTable.H"

//
// ================= Constructors ==========================
//
FunctionTable::FunctionTable() 
	//-------------------------------------------------
	// Pre : none
	// Post: functionTable_ is initialized
	//-------------------------------------------------
	//
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// NOTE: While there are a number of ways to initialize the arrary of structures,
	//       this way was choosen since it would easly allow future modifications,
	//       such as initialize structure from a file.
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	// --- ACOS FUNCTION 
	functionTable_[0].Name ="ACOS";
    functionTable_[0].NumberOfParameters = 1;

	// --- ASIN FUNCTION 
	functionTable_[1].Name ="ASIN";
    functionTable_[1].NumberOfParameters = 1;

	// --- ATAN FUNCTION 
	functionTable_[2].Name ="ATAN";
    functionTable_[2].NumberOfParameters = 1;

	// --- COS FUNCTION 
	functionTable_[3].Name ="COS";
    functionTable_[3].NumberOfParameters = 1;

	// --- COSH FUNCTION 
	functionTable_[4].Name ="COSH";
    functionTable_[4].NumberOfParameters = 1;

	// --- LN FUNCTION 
	functionTable_[5].Name ="LN";
    functionTable_[5].NumberOfParameters = 1;

	// --- LOG FUNCTION 
	functionTable_[6].Name ="LOG";
    functionTable_[6].NumberOfParameters = 1;

	// --- SIN FUNCTION 
	functionTable_[7].Name ="SIN";
    functionTable_[7].NumberOfParameters = 1;

	// --- SINH FUNCTION 
	functionTable_[8].Name ="SINH";
    functionTable_[8].NumberOfParameters = 1;

	// --- SQRT FUNCTION 
	functionTable_[9].Name ="SQRT";
    functionTable_[9].NumberOfParameters = 1;

	// --- TAN FUNCTION 
	functionTable_[10].Name ="TAN";
    functionTable_[10].NumberOfParameters = 1;

	// --- TANH FUNCTION 
	functionTable_[11].Name ="TANH";
    functionTable_[11].NumberOfParameters = 1;


}

//
// ================= Destructor ==========================
//
FunctionTable::~FunctionTable() 
	//-------------------------------------------------
	// Pre : none
	// Post: FunctionTable is destructed and cleaned up
	//-------------------------------------------------
{
}

//
// ================= Accessors ==========================
//

//
// ================= Member Methods ==========================
//

//
// get position of passed FunctionName in function table
//
int FunctionTable::FunctionPosition( /* IN    */ string FunctionName) const
	//-------------------------------------------------
	// Pre : FunctionName is assigned 
	// Post: if FunctionName is found in function table
	//          return position of functionName in table
	//       else
	//          return FUNCTION_NOT_FOUND
	//-------------------------------------------------
{

	int iLoop = 0;
	for (; 
		(iLoop < NUMBER_ENTRIES) && (functionTable_[iLoop].Name != FunctionName) ;
		iLoop++)
	{
	}
	return (iLoop < NUMBER_ENTRIES ? iLoop : FUNCTION_NOT_FOUND);
}

//
// check if passed FunctionName is acceptable Function
//
bool FunctionTable::IsFunction(/* IN    */ string FunctionName) const
	//-------------------------------------------------
	// Pre : FunctionName is assigned 
	// Post: if FunctionName is found in function table
	//          TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------

{
	return (FunctionPosition(FunctionName) != FUNCTION_NOT_FOUND);
}

//
// get number of parameters for passed Function name
//
int FunctionTable::NumberOfParameters( /* IN    */ string FunctionName) const
	//-------------------------------------------------
	// Pre : none
	// Post: SymbolTable is empty 
	//-------------------------------------------------
{
	int iPos = FunctionPosition(FunctionName);

	return (iPos != FUNCTION_NOT_FOUND ? functionTable_[iPos].NumberOfParameters : 0);	
}

//
// ================= Operators ==========================
//

//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs slot to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const FunctionTable &ft)
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

	os << std::left << std::setw(10)
		<<  "Function" 
		<< std::setw(3)
		<< " - "
		<< std::setw(20)
		<< "Number of Parameters" 
		<< std::endl;

	for(int fnum =	0; fnum < ft.NUMBER_ENTRIES; fnum++)
	{
		os << std::left
		   << std::setw(5)
	       << ft.functionTable_[fnum].Name	
		   << std::setw(3)
		   << " "
		   << std::setw(12)
		   << std::right
		   << ft.functionTable_[fnum].NumberOfParameters
		   << std::endl;
	}
	os  <<  std::endl
		<< std::endl;

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
