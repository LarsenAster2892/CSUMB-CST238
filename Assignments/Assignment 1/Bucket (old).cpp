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
Bucket::Bucket()
//-------------------------------------------------
// initailize bucket
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
int Bucket::Count(void)
//-------------------------------------------------
// Get count
// Pre : none
// Post: count is returned for bucket (includes overflow)
//-------------------------------------------------
{
	return (count_);
}

STR20 * Bucket::data(int slot_number) /* IN */
//-------------------------------------------------
// Get data
// Pre : none
// Post: data is returned for slot
//-------------------------------------------------
{
	 return (slots_[slot_number].data()); 
}

STR10 * Bucket::key(int slot_number) /* IN */
//-------------------------------------------------
// Get key
// Pre : none
// Post: key is returned for slot
//-------------------------------------------------
{
	return (slots_[slot_number].key()); 
}


int Bucket::Overflow(void)
//-------------------------------------------------
// Get overflow
// Pre : none
// Post: overflow is returned for bucket 
//-------------------------------------------------
{
	return (overflow_);
}

//
// ================= Mutators ==========================
//

//void Bucket::Count(int new_count)         /* IN  */
////-------------------------------------------------
//// Set Count
//// Pre : none
//// Post: count for bucket is set to new value
////-------------------------------------------------
//{
//
//	std::cout << " count = " << new_count << std::endl;
//	count_ = new_count;
//}
//
//
//void Bucket::data(int slot_number,        /* IN */
//				  const STR20 & new_data) /* IN */
////-------------------------------------------------
//// Set Data
//// Pre : none
//// Post: Data for slot(n)  is set to new value
////-------------------------------------------------
//{
//	slots_[slot_number].data(new_data);
//}
//
//
//void Bucket::key(int slot_number,        /* IN */
//				 const STR10 & new_key)  /* IN */
////-------------------------------------------------
//// Set key
//// Pre : none
//// Post: key for slot(n)  is set to new value
////-------------------------------------------------
//{
//	slots_[slot_number].key(new_key);
//
//}



void Bucket::Overflow(int new_overflow) /* IN */
//-------------------------------------------------
// Set Overflow
// Pre : none
// Post: overflow for bucket is set to new value
//-------------------------------------------------
{
	overflow_ = new_overflow;
}

//
// ================= Member Methods ==========================
//
void Bucket::Clear(void)
//-------------------------------------------------
// Clear bucket
// Pre : none
// Post: overflow and count are reset
//-------------------------------------------------
{
	count_ = 0;
	overflow_ = OVERFLOW_EMPTY;
}


bool Bucket::HasKey(const STR10 &  key,    /* IN  */
					int &  slot_number)       /* OUT */
//-------------------------------------------------
// Searches Bucket for key
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


bool Bucket::Insert(const STR10 &  key,    /* IN */
					const STR20 & data)    /* IN */
//--------------------------------------------------
// insert key/data
// Pre : key and data are not null
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
{
	int temp = count_;
	count_++;
	return (temp);

}

//
// --- STREAM OVERLOAD OPERATORS ---
std::ostream & operator<<(std::ostream &os,   /* INOUT */
						  const Bucket &b)    /* IN    */
//-------------------------------------------------------
// Outputs bucket to iostream
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
	 os << "  count " << b.count_;
	 os << std::endl
		<< std::endl;

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
