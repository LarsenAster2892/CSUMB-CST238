//********************************************************
// File Name   : QuickSortType.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for QuickSortType Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <iostream>
#include <iomanip>

#include "SortType.h"

#ifndef QUICKSORTTYPE_h
#define QUICKSORTTYPE_h

//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A Sort type Class 
//
// Base Classes: SortType
//
//===================================================================


class QuickSortType : public SortType
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
	   DataContainer * pDC_;		   // Pointer to DataContainer Object	
        
		//Internal Recursive Sort Routine
		void QSort (/* IN    */ int start,
			        /* IN    */ int finish);    
			//-------------------------------------------------
			// Pre : start and finish are assigned
			//       and pDC_[start..finish] is assigned
			// Post: pDC_[start..finish] are sorted Ascending
			//-------------------------------------------------
		
		//Internal Recursive Sort Routine (descending)
		void QSortDescending (/* IN    */ int start,
			                  /* IN    */ int finish);    
			//-------------------------------------------------
			// Pre : start and finish are assigned
			//       and pDC_[start..finish] is assigned
			// Post: pDC_[start..finish] are sorted Descending
			//-------------------------------------------------

	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:
		
		
	
	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		QuickSortType(/* IN    */ SortOrderType SortOrder = AscendingOrder);
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~QuickSortType();

		//
		// ============= ACCESSORS =====================
		//
		
		//
		// ============= MUTATORS =====================
		//


		//
		// ============= MEMBER METHODS =====================
		//


		void Sort(/* INOUT */ DataContainer & sortDC);
			//-------------------------------------------------
			// Pre : Data_ is assigned
			// Post: Data_[0..Last] are sorted
			//-------------------------------------------------


};

#endif