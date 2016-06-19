//********************************************************
// File Name   : FunctionTable.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Header file for FunctionTable class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>
using std::string;

#ifndef FUNCTIONTABLE_h
#define FUNCTIONTABLE_h


//
// --- DEFINED TYPES  -----
//
//enum constvalues {numEntries = 12}

struct FunctionEntryType {
	string 	Name;  
	int		NumberOfParameters;
};


//struct FunctionEntryType;		// Forward declaration, Hidden in Implementation file



class FunctionTable
{

	//
	// -- data members -----
	//
	private:
		//
		// --- CONSTANTS -----
		// 
		static const int NUMBER_ENTRIES = 12;
		static const int FUNCTION_NOT_FOUND = -1;
	
		// --- Private Member Data -------	
		FunctionEntryType functionTable_[NUMBER_ENTRIES];

		// --- Private Member Functions ----

		int FunctionPosition(/* IN    */ string	FunctionName);
			//-------------------------------------------------
			// Pre : FunctionName is assigned 
			// Post: if FunctionName is found in function table
			//          return position of functionName in table
			//       else
			//          return FUNCTION_NOT_FOUND
			//-------------------------------------------------

	public:
		// --- Constructors ----
		FunctionTable();
	
		// --- Destructor ----
		virtual ~FunctionTable();

		// --- Accessors -----
		long Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total entries in function Table
			//-------------------------------------------------

		// --- Mutators -------


		// --- Member Methods ---

		bool IsFunction(/* IN    */ string	FunctionName) const;
			//-------------------------------------------------
			// Pre : FunctionName is assigned 
			// Post: if FunctionName is found in function table
			//          TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------

		int NumberOfParameters(/* IN    */ string	FunctionName) const;
			//-------------------------------------------------
			// Pre : FunctionName is assigned 
			// Post: if FunctionName is found in function table
			//          number parameters is returned
			//       else
			//          zero is returned
			//-------------------------------------------------


};
	std::ostream & operator<<(std::ostream &os, const FunctionTable &ft);
#endif