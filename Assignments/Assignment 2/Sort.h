//********************************************************
// File Name   : Sort.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for Sort Abstract Base Class (ABC)
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>


#ifndef SORT_h
#define SORT_h

//
// --- CONSTANTS -----
// 
//
// --- CONSTANTS -----
// 
const int MAX_ITEMS = 10;		// The number of elements in the arrary

const int MAX_RANGE = 1000;		// The upper limit of the range of array values

//
// --- DEFINED TYPES  -----
//
typedef int DataType;


class Sort
{

	//
	// -- data members -----
	//
	private:
		DataType	Data_[MAX_ITEMS];
		
	
	// --- private functions ----

	public:
		// --- Constructors ----
		Sort();
	
		// --- Destructor ----
		virtual ~Sort();

		// --- Accessors -----

		// --- Mutators -------



		virtual void SortData(void) = 0;
			//-------------------------------------------------
			// Pre : <none>
			// Post: All items in data_ are soreted in ascending order
			//-------------------------------------------------


};

#endif