//********************************************************
// File Name   : SearchType.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for SearchType Abstract Base Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataContainer.h"

//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class (ABC)
//
//
//===================================================================

#ifndef SEARCHTYPE_h
#define SEARCHTYPE_h

class SearchType
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:

		
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
		SearchType();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~SearchType();

		//
		// ============= ACCESSORS =====================
		//

		//
		// ============= MUTATORS =====================
		//


		//
		// ============= MEMBER METHODS =====================
		//

		virtual int Search(/*   IN   */ DataContainer & searchDC,
			               /*   IN   */ Data & searchItem) = 0;
			//---------------------------------------------------------
			// Pre : SearchDC is assigned and searchDC is in sort order
			//       and searchItem is assigned.
			// Post: if searchItem is contained in searchDC,
			//          true is returned
			//       else 
			//			false is returned
			//---------------------------------------------------------


};

#endif
