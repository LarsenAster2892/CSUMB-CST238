//********************************************************
// File Name   : Bucket.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Class member functions for Bucket Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "BUCKET.H"

//
// ================= Constructors ==========================
//

//
// initailize bucket
//
Bucket::Bucket()
//-------------------------------------------------
// Pre : none
// Post: Bucket count and overflow are initialized
//-------------------------------------------------
{
	count_ = 0;
	overflow_ = OVERFLOW_EMPTY;
}

//
// ================= Accessors ==========================
//

//
// Get count
//
int Bucket::Count(void) const
//-------------------------------------------------
// Pre : none
// Post: count is returned for bucket (includes overflow)
//-------------------------------------------------
{
	return (count_);
}


//
// Get data
//
STR20 * Bucket::data(/* IN    */ int slot_number)
//-------------------------------------------------
// Pre : none
// Post: data is returned for slot
//-------------------------------------------------
{
	 return (slots_[slot_number].data()); 
}

//
// Get key
//
STR10 * Bucket::key(/* IN    */ int slot_number)
//-------------------------------------------------
// Pre : none
// Post: key is returned for slot
//-------------------------------------------------
{
	return (slots_[slot_number].key()); 
}


//
// Get overflow
//
int Bucket::Overflow(void)
//-------------------------------------------------
// Pre : none
// Post: overflow is returned for bucket 
//-------------------------------------------------
{
	return (overflow_);
}

//
// ================= Mutators ==========================
//


//
// Set Count
//
void Bucket::Count(/* IN    */ int new_count)
//-------------------------------------------------
// Pre : none
// Post: count for bucket is set to new value
//-------------------------------------------------
{

	count_ = new_count;
}


//
// Set Data
//
void Bucket::data(/* IN    */ int slot_number,        
				  /* IN    */ const STR20 & new_data) 
//-------------------------------------------------
// Pre : none
// Post: Data for slot(n)  is set to new value
//-------------------------------------------------
{
	slots_[slot_number].data(new_data);
}


//
// Set key
//
void Bucket::key(/* IN    */ int slot_number,      
				 /* IN    */ const STR10 & new_key)
//-------------------------------------------------
// Pre : none
// Post: key for slot(n)  is set to new value
//-------------------------------------------------
{
	slots_[slot_number].key(new_key);

}


//
// Set Overflow
//
void Bucket::Overflow(/* IN    */ int new_overflow)
//-------------------------------------------------
// Pre : none
// Post: overflow for bucket is set to new value
//-------------------------------------------------
{
	overflow_ = new_overflow;
}


//
// ================= Member Methods ==========================
//


//
// Clear bucket
//
void Bucket::Clear(void)
//-------------------------------------------------
// Pre : none
// Post: overflow and count are reset
//-------------------------------------------------
{
	count_ = 0;
	overflow_ = OVERFLOW_EMPTY;
}


//
// Searches Bucket for key
//
bool Bucket::HasKey(/* IN    */ const STR10 &  key,
					/* OUT   */ int &  slot_number)
//-------------------------------------------------
// Pre : key contains non null value
// Post: if bucket contains key,
//         slot_number will hold slot position
//         and true will be returned
//       else
//         slot_number will hold -99
//         and false will be returned
//-------------------------------------------------
{

	int snum = 0;
	
	for (; ((snum < MAX_SLOTS) && (!slots_[snum].KeyMatch(key))); snum++)
	{
	}
	slot_number = (snum < MAX_SLOTS ? snum : -99);
	
	return (slot_number != -99);
}


//
// insert key/data
//
bool Bucket::Insert(/* IN    */ const STR10 &  key,
					/* IN    */ const STR20 & data)
//--------------------------------------------------
// Pre : key and data are assigned
// Post: if bucket is not full,
//          key/data is inserted and true is returned
//       else
//          false is returned
//--------------------------------------------------
{
	bool return_value = true;
	if (count_ > (MAX_SLOTS - 1)) 
		return_value = false;
	else
	{
		slots_[count_].key(key);
		slots_[count_].data(data);
		count_++;
	}
	return return_value;
}

//
// ================= Operators ==========================
//


//
// --- (++) Operator function (postfix) ---
//
int Bucket::operator ++(int)
//--------------------------------------------------
// Pre : 
// Post: bucket slot used count is incremented by one
//--------------------------------------------------
{
	int temp = count_;
	count_++;
	return (temp);

}

//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs bucket to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const Bucket &b)
//-------------------------------------------------------
// Pre : os is valid iostream b is valid bucket
// Post: iostream os contains outputted bucket 
//-------------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();
	
	for(int snum =	0; snum < MAX_SLOTS; snum++)
	{
		os << std::left
		   << std::setw(5)
	       << " " 	
		   << std::setw(5)
		   << "Slot"
		   << std::setw(2)
		   << snum + 1
		   << std::setw(3)
		   << ": "
		   << b.slots_[snum] 
		   << std::endl;
	}
	os << std::left
	   << std::setw(5)
	   << " "
	   << std::setw(18)
	   << "Overflow Pointer: ";
     
	 if (b.overflow_ == OVERFLOW_EMPTY)
	 {	 
		 os << std::setw(8)
			<< "<EMPTY>";
	 }
	 else
	 {	  
		 os << std::setw(4)
			<< (b.overflow_ + 1)
			<< std::setw(4)
			<< " ";
	 }
	 os << std::endl
		<< std::endl;

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
