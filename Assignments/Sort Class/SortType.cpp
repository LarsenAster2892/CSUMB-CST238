//***********************************************************************
// File Name   : SortType.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for SortType Abstract Base Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "SortType.h"

//
// ================= Constructors ==========================
//
SortType::SortType(/* IN    */ SortOrderType SortOrder)
	//-------------------------------------------------
	// Pre : none
	// Post: Class is initialized and sort order is set
	//-------------------------------------------------
{
	SortOrder_ = SortOrder;	

}


//
// ================= Destructor ==========================
//
SortType::~SortType()
	//-------------------------------------------------
	// Pre : none
	// Post: Class is destructed and cleaned up
	//-------------------------------------------------
{
}

//
// ================= Accessor ==========================
//
//
// =====  Get sort ordering 


//
// - Ascending ?
//  
bool SortType::SortAscending(void)
	//------------------------------------------------------
	// Pre : <none>
	// Post: If SortOrder_  == SortOrderType::AscendingOrder
	//          Returns true
	//       Else
	//          Returns false
	//------------------------------------------------------
{
	return (SortOrder_ == AscendingOrder);
}


//
//  - Descending ? 
//

bool SortType::SortDescending(void)
	//-------------------------------------------------------
	// Pre : <none>
	// Post: If SortOrder_  == SortOrderType::DescendingOrder
	//          Returns true
	//       Else
	//          Returns false
	//-------------------------------------------------------
{
	return (SortOrder_ == DescendingOrder);
}


//
// ================= MUTATORS ==========================
//
//
//
// - Ascending ?
//  
void SortType::SetAscending(void)
	//-------------------------------------------------
	// Pre : <none>
	// Post: Sort order is set to Ascending
	//-------------------------------------------------
{
	SortOrder_ = AscendingOrder;
}


//
//  - Descending ? 
//

void SortType::SetDescending(void)
	//-------------------------------------------------
	// Pre : <none>
	// Post: Sort order is set to Descending
	//-------------------------------------------------
{
	SortOrder_ = DescendingOrder;
}

//
// ================= Member Methods ==========================
//
//