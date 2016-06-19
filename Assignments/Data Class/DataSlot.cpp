//***********************************************************************
// File Name   : DataSlot.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for DataSlot Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "DataSlot.h"

//
// ================= Constructors ==========================
//
DataSlot::DataSlot()
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
}


//
// ================= Destructor ==========================
//
DataSlot::~DataSlot()
//-------------------------------------------------
// Pre : none
// Post: Class is destructed
//-------------------------------------------------
{
}

//
// ================= Copy Constructor ==========================
//
DataSlot::DataSlot(/* IN    */ DataSlot & copyItem)
//-------------------------------------------------
// Pre : copyItem is Assigned
// Post: (*this) is assigned values of copyItem
//-------------------------------------------------
{
	Slot::key(copyItem.key());
	Slot::data(copyItem.data());

};

//
// ================= Member Methods ==========================
//
// ============= ACCESSORS =====================
//
//
//
//  -----Get data -----
//
STR20 & DataSlot::data(void)
//-------------------------------------------------
// Pre : none
// Post: key is returned
//-------------------------------------------------
{
	return (Slot::data());
}


//
//
// --- Get Data Value ---
// 
//

STR10 & DataSlot::Get(void)
//-------------------------------------------------
// Pre : <none>
// Post: return item key values
//-------------------------------------------------
{
	return (Slot::key());
}

//
//  -----Get key -----
//
STR10 & DataSlot::key(void)
//-------------------------------------------------
// Pre : none
// Post: key is returned
//-------------------------------------------------

{
	return (Slot::key());
}



//
// ============= MUTATORS =====================
//
//
//  -----Set data -----
//

void DataSlot::data(/* IN    */ const STR20 & new_data)
//-------------------------------------------------
// Pre : none
// Post: data is set to new value
//-------------------------------------------------
{
	Slot::data(new_data);
}

//
//  -----Set key -----
//

void DataSlot::key(/* IN    */ const STR10 & new_key)
//-------------------------------------------------
// Pre : none
// Post: key is set to new value
//-------------------------------------------------
{
	Slot::key(new_key);
}


//
// --- Sets new value
//
void DataSlot::Set(/* IN    */ Slot & dataItem)
//-------------------------------------------------
// Pre : dataItem is assigned
// Post: set new value for Items
//-------------------------------------------------
{
	Slot::key(dataItem.key());
	Slot::data(dataItem.data());

}


//
// ================= Operators ==========================
//


bool DataSlot::operator <  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataSlot
// Post: if dItem key is greater than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataSlot * pDI = (DataSlot *) &dItem;   // Force base class item to drived class (upcasting)
											// User beware 

	return (strcmp(Slot::key(), pDI->Get()) < 0);
}

bool DataSlot::operator >  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataSlot
// Post: if dItem key is less than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataSlot * pDI = (DataSlot *) &dItem;  // Force base class item to drived class (upcasting)
										   // User beware


	return (strcmp(Slot::key(), pDI->Get()) > 0);
}


bool DataSlot::operator ==  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataSlot
// Post: if dItem key is equal to (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataSlot * pDI = (DataSlot *) &dItem;
	
	return (strcmp(Slot::key(), pDI->Get()) == 0);
}





//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs slot to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const DataSlot &ds)
//----------------------------------------------------
// Pre : os is valid iostream & s is valid slot
// Post: iostream os contains outputted slot
//-------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();

	
	os << (Slot) ds;    // Cast as a Slot as use Slot output stream function

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
