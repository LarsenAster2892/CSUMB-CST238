//********************************************************
// File Name   : SortType.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for SortType Abstract Base Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataContainer.h"

#ifndef SORTTYPE_h
#define SORTTYPE_h

//
// --- CONSTANTS -----
// 
const char DEFAULT_ORDER = 'A';		// The number of elements in the arrary

//
// --- ENUMERATED TYPES -----
// 

enum SortOrderType
{
    AscendingOrder = 'A',
    DescendingOrder = 'D',
};


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class (ABC)
//
//
//===================================================================

class SortType
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:

		SortOrderType SortOrder_;   // Track order of sort
		
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
		SortType(/* IN    */ SortOrderType SortOrder = AscendingOrder);
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~SortType();

		//
		// ============= ACCESSORS =====================
		//
	
		bool SortAscending(void);
			//-----------------------------------------------------
			// Pre : <none>
			// Post: If SortOrder_  == SortOrderType::AscendingOrder
			//          Returns true
			//       Else
			//          Returns false
			//------------------------------------------------------

		
		bool SortDescending(void);
			//-------------------------------------------------------
			// Pre : <none>
			// Post: If SortOrder_  == SortOrderType::DescendingOrder
			//          Returns true
			//       Else
			//          Returns false
			//-------------------------------------------------------


		//
		// ============= MUTATORS =====================
		//
		void SetAscending(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: Sort order is set to Ascending
			//-------------------------------------------------

		
		void SetDescending(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: Sort order is set to Descending
			//-------------------------------------------------


		//
		// ============= MEMBER METHODS =====================
		//

		virtual void Sort(/* INOUT */ DataContainer & sortDC) = 0;
			//-------------------------------------------------
			// Pre : Data_ is assigned
			// Post: Data_[0..Last] are sorted
			//-------------------------------------------------


};

#endif