//********************************************************
// File Name   : Sort.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for Sort Abstract Base Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>


#ifndef SORTTYPE_h
#define SORTTYPE_h

//
// --- CONSTANTS -----
// 
//
// --- CONSTANTS -----
// 
const int MAX = 10;		// The number of elements in the arrary
//
// --- DEFINED TYPES  -----
//
typedef int DataType;


class SortType
{

	//
	// -- data members -----
	//
	private:
	   //The array declaration
		DataType Data_[MAX];

		
	
	// --- private functions ----

	public:
		// --- Constructors ----
		SortType();
	
		// --- Destructor ----
		virtual ~SortType();

		// --- Accessors -----
		
		// --- Mutators -------

		// --- Member Methods -------

		virtual void Sort(void) = 0;
};

#endif