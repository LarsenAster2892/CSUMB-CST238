//********************************************************
// File Name   : Slot.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Class member functions for Slot Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "SLOT.H"


//
// ================= Constructors ==========================
//

//
// initailize slot
//
Slot::Slot(/* IN    */ const STR10 key,
		   /* IN    */ const STR20 data)
//-------------------------------------------------
// Pre : none
// Post: slot key/data are initialized
//-------------------------------------------------
{
	strcpy(key_ , key);
	key_[10] = '\0';

	strcpy(data_, data);
	data_[20] = '\0';
}



//
// ================= Accessors ==========================
//

//
// Get data
//
STR20 * Slot::data(void)
//-------------------------------------------------
// Pre : none
// Post: data is returned
//-------------------------------------------------
{
	 return (&data_); 
}

//
// Get key
//
STR10 * Slot::key(void) 
//-------------------------------------------------
// Pre : none
// Post: key is returned
//-------------------------------------------------
{
	return (&key_); 
}

//
// ================= Mutators ==========================
//

//
// Set data
//
void Slot::data(/* IN    */ const STR20 & new_data)
//-------------------------------------------------
// Pre : none
// Post: data is set to new value
//-------------------------------------------------
{
	strcpy(data_,new_data);
	data_[20] = '\0';
}

//
// Set key
//
void Slot::key(/* IN    */ const STR10 & new_key)
//-------------------------------------------------
// Pre : none
// Post: key is set to new value
//-------------------------------------------------
{
	strcpy(key_,new_key);
    key_[10] = '\0';
}



//
// ================= Member Methods ==========================
//

//
// Test for Match of key
//
bool Slot::KeyMatch(/* IN    */ const STR10 & test_key)
//----------------------------------------------------
// Pre : none
// Post: key is set to new value
//-------------------------------------------------
{
	return ((strcmp(key_,test_key) == 0));
}

//
// ================= Operators ==========================
//

//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs slot to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const Slot &s)
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

	if ((strlen(s.key_) > 0) || (strlen(s.data_) > 0))
	{
		os << std::left << std::setw(5)
		   <<  "Key:" 
		   << std::setw(KEYSIZE + 2)
		   << (strlen(s.key_) > 0 ? s.key_ : "<EMPTY>")
		   << std::setw(3)
		   << " - "
		   << std::setw(7)
		   << "Data:" 
		   << std::setw(DATASIZE + 2)
		   << (strlen(s.data_) > 0 ? s.data_ : "<EMPTY>");
	}
	else
	{
		os << std::left << std::setw(8)
		   << "<EMPTY>";
	}

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
