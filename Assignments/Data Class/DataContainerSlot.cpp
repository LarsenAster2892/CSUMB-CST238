//***********************************************************************
// File Name   : DataContainerSlot.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for DataContainerSlot Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "DataContainerSlot.h"

//
// ================= Constructors ==========================
//
DataContainerSlot::DataContainerSlot(/* IN    */ int NumberDataItems)
	//-------------------------------------------------
	// Pre : NumberDataItems is assigned
	// Post: Class is instantiated with Data[NumberSortItems]
	//-------------------------------------------------
{
	DataTable_ = new DataSlot * [NumberDataItems];
	SizeDC_ = NumberDataItems;
	NextItem_ = 0;
}


//
// ================= Destructor ==========================
//
DataContainerSlot::~DataContainerSlot()
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

DataSlot & DataContainerSlot::GetItem(/* IN    */ int ItemNumber) const
	//-------------------------------------------------
	// Pre : ItemNumber is assigned 
	//       and 0 <= ItemNumber <= SizeDC_
	// Post: Data Object at DataTable[ItemNumber] is returned
	//-------------------------------------------------
{
	DataSlot * tmpItem = new DataSlot;
	tmpItem->key(DataTable_[ItemNumber]->key());
	tmpItem->data(DataTable_[ItemNumber]->data());
	return (*tmpItem);
}


//
// ============= MUTATORS =====================
//
//
// Add Data to Data Container
//
bool DataContainerSlot::AddItem(/* IN    */ DataSlot & inItem)
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
		DataSlot * tmpItem = new DataSlot;
		tmpItem->key(inItem.key());
		tmpItem->data(inItem.data());

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
//
// Clear DataTable
//
void DataContainerSlot::Clear(void)
	//-------------------------------------------------
	// Pre : <none>
	// Post: DataTable is Cleared and Size is reset
	//-------------------------------------------------
{
	delete [] DataTable_;
	DataTable_ = new DataSlot * [SizeDC_];
    NextItem_ = 0;

}

//
//
// Swap two Items
//

void DataContainerSlot::SwapItems(/* IN    */ int ItemNumberA,
								  /* IN    */ int ItemNumberB)
	//-------------------------------------------------
	// Pre : ItemNumberA and ItemNumberB are assigned 
	//       and 0 <= ItemNumberA <= SizeDC_
	//       and 0 <= ItemNumberB <= SizeDC_
	// Post: Items in DataTable at ItemNumberA and
	//       ItemNumberB are swapped
	//-------------------------------------------------

{

	DataSlot * pTmp;
	pTmp = DataTable_[ItemNumberA];
	DataTable_[ItemNumberA] = DataTable_[ItemNumberB];
	DataTable_[ItemNumberB] = pTmp;

}

void DataContainerSlot::PrintItems()
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


