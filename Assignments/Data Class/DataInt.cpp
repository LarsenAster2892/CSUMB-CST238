//***********************************************************************
// File Name   : DataInt.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for DataInt Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "DataInt.h"

//
// ================= Constructors ==========================
//
DataInt::DataInt()
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
}


//
// ================= Destructor ==========================
//
DataInt::~DataInt()
	//-------------------------------------------------
	// Pre : none
	// Post: Class is destructed
	//-------------------------------------------------
{
}

//
// ================= Member Methods ==========================
//
// ============= ACCESSORS =====================
//
//
// --- Get new value ---
//

int DataInt::Get(void)
//-------------------------------------------------
// Pre : <none>
// Post: return item values
//-------------------------------------------------
{
	return (DataItem_);
}

//
// ============= MUTATORS =====================
//
//
// --- Sets new value
//
void DataInt::Set(/* IN    */ int dataItem)
//-------------------------------------------------
// Pre : dv is assigned
// Post: set new value for Items
//-------------------------------------------------
{
	DataItem_ = dataItem;
}
//

//
// ================= Operators ==========================
//


bool DataInt::operator <  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataInt
// Post: if dItem key is greater than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataInt * pDI = (DataInt *) &dItem; // Force base class item to drived class (upcasting)

	return (DataItem_ < pDI->Get());
}



bool DataInt::operator >  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataInt
// Post: if dItem key is less than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataInt * pDI = (DataInt *) &dItem;

	return (DataItem_ > pDI->Get());
}


bool DataInt::operator ==  (/* IN    */ Data & dItem) 
//-----------------------------------------------------------
// Pre : dItem is assigned and is of type DataInt
// Post: if dItem key is equal to (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	DataInt * pDI = (DataInt *) &dItem;

	return (DataItem_ == pDI->Get());
}

DataInt::operator int()
{
	return (DataItem_);
}

//
// --- STREAM OVERLOAD OPERATORS ---
// Inputs DataInt from iostream

std::istream & operator>>(/* INOUT */ std::istream &is, 
						  /* OUT   */ DataInt &di)
{
	//int tempNum = 0;
	char first_char, next_char;

	is >> first_char;
	next_char = is.peek();
	is.putback(first_char);

	if ((first_char < '0' || first_char >'9') && 
		((first_char == '-' || first_char != '+') &&
		(next_char < '0' || next_char > '9')))
	{
		is.setf( std::ios::failbit);
	}
	else {
		bool success;
		success = ((is >> di.DataItem_) ? true : false);
	}
	return is;
}


// Outputs DataInt to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const DataInt &di)
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

	os << di.DataItem_;    

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
