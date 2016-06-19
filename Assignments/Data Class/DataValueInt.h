//********************************************************
// File Name   : Data.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for Data Abstract Base Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "DataValue.h"

#ifndef DATAVALUEINT_h
#define DATAVALUEINT_h

//
// --- CONSTANTS -----
// 
//
// --- CONSTANTS -----
// 
//const int MAX_SLOTS = 10;		// The number of elements in the arrary

//
// --- DEFINED TYPES  -----
//


class DataValueInt : public DataValue
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		int DataValue_;
		
	
	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//

	protected:
		

	public:
		// --- Constructors ----
		DataValueInt() {};
	
		// --- Destructor ----
		virtual ~DataValueInt() {};

		int   Get(void) {return (DataValue_);};
		void  Set(int dv) {DataValue_ = dv;};
};

#endif