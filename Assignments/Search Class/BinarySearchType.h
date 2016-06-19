//********************************************************
// File Name   : BinarySearchType.h       
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
#include "SearchType.h"


#ifndef BINARYSEARCHTYPE_h
#define BINARYSEARCHTYPE_h

//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A Search Type Class 
//
// Base Classes: Search
//
//===================================================================


class BinarySearchType : public SearchType
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
	    DataContainer * pDC_;		   // Pointer to DataContainer Object
		Data * pValue_;
        
		//Internal Recursive Search Routine
		int BinarySearch(/* IN    */ int First,
			         	 /* IN    */ int Last);
			//-------------------------------------------------
			// Pre : First, Last and Value are assigned
			//       and 0 <= First, Last <= SIZE-1, 
			//           where SIZE is the maximum size of the array,
			//       and pDC_[First..Last] and pValue_ are assigned
			// Post: pDC_ has been search for Value point to by pValue_
			//       if Value is found
			//          returns index within DataContainer
			//       else
			//			returns -1
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
		BinarySearchType();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~BinarySearchType();

		//
		// ============= ACCESSORS =====================
		//
		
		//
		// ============= MUTATORS =====================
		//


		//
		// ============= MEMBER METHODS =====================
		//


		int Search(/* IN    */ DataContainer & searchDC,
				   /* IN    */ Data & searchValue);
			//-------------------------------------------------
			// Pre : sortDC and Value are assigned
			//       and sortDC is sorted in ascending order
			// Post: sortDC has been searched for Value
			//       if Value is found
			//          returns index within DataContainer
			//       else
			//			returns -1
			//-------------------------------------------------


};

#endif