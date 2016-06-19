//********************************************************
// File Name   : QuickSort.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for QucikSort class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>


#ifndef QUICKSORT_h
#define QUICKSORT_h

//
// --- CONSTANTS -----
// 
//
// --- CONSTANTS -----
// 
//const int MAX_SLOTS = 10;		// The number of elements in the arrary
//
//const int MAX_RANGE = 1000;		// The upper limit o fthe range of array values

//
// --- DEFINED TYPES  -----
//


class Sort : public Sort
{

	//
	// -- data members -----
	//
	private:

		
	
	// --- private functions ----

	public:
		// --- Constructors ----
		QuickSort();
	
		// --- Destructor ----
		virtual ~QuickSort();

		// --- Accessors -----

		// --- Mutators -------



		void SortData(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: All items in data_ are soreted in ascending order
			//-------------------------------------------------


};

#endif