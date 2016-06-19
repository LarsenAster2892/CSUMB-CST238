//***********************************************************************
// File Name   : DataContainerInt.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for DataContainerInt Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "DataContainerInt.h"

//
// ================= Constructors ==========================
//
DataContainerInt::DataContainerInt(/* IN    */ int NumberDataItems)
	//-------------------------------------------------
	// Pre : NumberDataItems is assigned
	// Post: Class is instantiated with Data[NumberSortItems]
	//-------------------------------------------------
{
	DataTable_ = new DataInt * [NumberDataItems];
	SizeDC_ = NumberDataItems;
	NextItem_ = 0;
}


//
// ================= Destructor ==========================
//
DataContainerInt::~DataContainerInt()
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


DataInt & DataContainerInt::GetItem(/* IN    */ int ItemNumber) const
	//-------------------------------------------------
	// Pre : ItemNumber is assigned 
	//       and 0 <= ItemNumber <= SizeDC_
	// Post: Data Object at DataTable[ItemNumber] is returned
	//-------------------------------------------------
{
	DataInt * tmpItem = new DataInt;
	tmpItem->Set(DataTable_[ItemNumber]->Get());
	return (*tmpItem);
}


//
// ============= MUTATORS =====================
//

//
// Add Data to Data Container
//
bool DataContainerInt::AddItem(/* IN    */ DataInt & inItem)
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
		DataInt * tmpItem = new DataInt;
		tmpItem->Set(inItem.Get());
		DataTable_[NextItem_] = tmpItem;
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
// Clear DataTable
//
void DataContainerInt::Clear(void)
	//-------------------------------------------------
	// Pre : <none>
	// Post: DataTable is Cleared and Size is reset
	//-------------------------------------------------
{
	delete [] DataTable_;
	DataTable_ = new DataInt * [SizeDC_];
    NextItem_ = 0;

}

//
//
// Swap two Items
//

void DataContainerInt::SwapItems(/* IN    */ int ItemNumberA,
								 /* IN    */ int ItemNumberB)
	//-------------------------------------------------
	// Pre : ItemNumberA and ItemNumberB are assigned 
	//       and 0 <= ItemNumberA <= SizeDC_
	//       and 0 <= ItemNumberB <= SizeDC_
	// Post: Items in DataTable at ItemNumberA and
	//       ItemNumberB are swapped
	//-------------------------------------------------

{
	DataInt * pTmp;
	pTmp = DataTable_[ItemNumberA];
	DataTable_[ItemNumberA] = DataTable_[ItemNumberB];
	DataTable_[ItemNumberB] = pTmp;

}


void DataContainerInt::PrintItems()
	//-------------------------------------------------
	// Pre : ItemNumberA and ItemNumberB are assigned 
	//       and 0 <= ItemNumberA <= SizeDC_
	//       and 0 <= ItemNumberB <= SizeDC_
	// Post: Items in DataTable at ItemNumberA and
	//       ItemNumberB are swapped
	//-------------------------------------------------

{
	
	for (int iLoop = 0; iLoop < SizeDC_ ; iLoop++)
	{

		std::cout << "     Number"					// Announce Generated Random Number
			      << std::right
			      << std::setw(3)
			      << iLoop + 1
			      << std::left
			      << std::setw(3)
			      << " - "
  			      << std::right
			      << std::setw(6)
			      << GetItem(iLoop)
				  << std::endl;

	}
	std::cout << std::endl;

}

