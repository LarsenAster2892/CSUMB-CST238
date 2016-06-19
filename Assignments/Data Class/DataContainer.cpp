//***********************************************************************
// File Name   : DataContainer.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for DataContainer Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "DataContainer.h"

//
// ================= Constructors ==========================
//
DataContainer::DataContainer(/* IN    */ int NumberDataItems)
	//-------------------------------------------------
	// Pre : NumberDataItems is assigned
	// Post: Class is instantiated with Data[NumberSortItems]
	//-------------------------------------------------
{
	DataTable_ = new Data * [NumberDataItems];
	SizeDC_ = NumberDataItems;
	NextItem_ = 0;
}


//
// ================= Destructor ==========================
//
DataContainer::~DataContainer()
	//-------------------------------------------------
	// Pre : none
	// Post: DataTable_ is deleted and Class is destructed
	//-------------------------------------------------
{
	delete [] DataTable_;
}
//
// ============= ACCESSORS =====================
//
//
//
// Get an Item
//


Data & DataContainer::GetItem(/* IN    */ int ItemNumber) const
	//-------------------------------------------------
	// Pre : ItemNumber is assigned 
	//       and 0 <= ItemNumber <= SizeDC_
	// Post: Data Object at DataTable[ItemNumber] is returned
	//-------------------------------------------------
{
	return (*DataTable_[ItemNumber]);
}

//
//
// Get Table Size
//
int DataContainer::SizeDC(void)
	//-------------------------------------------------
	// Pre : SizeDC_ is assigned
	// Post: SizeDC is returned
	//-------------------------------------------------
{
	return (SizeDC_);
}

//
// ============= MUTATORS =====================
//
//
// Add Data to Data Container
//
bool DataContainer::AddItem(/* IN    */ Data & inItem)
	//-------------------------------------------------
	// Pre : !IsFull
	// Post: if !IsFull
	//          inItem is Add to DataType
	//          and true is returned
	//       else
	//          false is returned
	//-------------------------------------------------
{
	bool rtnValue = true;

	if (!IsFull())
	{
		*DataTable_[NextItem_] = inItem;
		NextItem_++;
	}
	else
	{
		rtnValue = false;
	}
	
	return (rtnValue);
}



//
// ================= Member Methods ==========================
//



//
//
// Check for Full Table
//

bool DataContainer::IsFull(void)
	//-------------------------------------------------
	// Pre : <none>
	// Post: if NextItem_ > SizeDC_
	//          returns true
	//       else
	//          returns false
	//-------------------------------------------------
{
	return (NextItem_ > SizeDC_);
}



