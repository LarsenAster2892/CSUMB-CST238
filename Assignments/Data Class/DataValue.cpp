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
#include "DataVaule.h"

//
// ================= Constructors ==========================
//
DataValue::DataValue()
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
}


//
// ================= Destructor ==========================
//
DataValue::~DataValiueInt()
	//-------------------------------------------------
	// Pre : none
	// Post: Class is destructed
	//-------------------------------------------------
{
}

//
// ================= Member Methods ==========================
//
int DataInt::Get(void)
{
	return (DataItem_);
}


void DataInt::Set(int dataItem)
{
	DataItem_ = dataItem;
}
//
// --- Compare Functions
//
int DataInt::CompareTo(DataInt * DataItem)
{
	int returnValue = 0;

	
}

bool DataInt::IsEqual(DataInt * DataItem)
{
	return ((*this).Get() == DataItem->Get());	
}


bool DataInt::IsLessThan(DataInt * DataItem)
{
	return (DataItem_ == DataItem->Get());
	
}

bool DataInt::IsGreaterThan(DataInt * DataItem)
{
	return (DataItem_ == DataItem->Get());
	
}

//
// ================= Operators ==========================
//

bool DataInt::operator <  (Data & d) 
{
	return (IsLessThan(&d));
}

bool DataInt::operator ==  (Data & d) 
{
	return (IsEqual(&d));
}

bool DataInt::operator >  ( Data & d) 
{
	return (IsGreaterThan(&d));
}
