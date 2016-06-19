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

#ifndef DATAVALUE_h
#define DATAVALUE_h

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


class DataValue
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		
		
	
	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//

	protected:


	public:
		// --- Constructors ----
		DataValue() {};
	
		// --- Destructor ----
		virtual ~DataValue() {};
		float Get(void) {return (0.0);};
		void  Set(void) {};


};

#endif