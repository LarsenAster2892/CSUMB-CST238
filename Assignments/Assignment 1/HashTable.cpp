//********************************************************
// File Name   : HashTable.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Class member functions for HashTable Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "HASHTABLE.H"


//
// ================= Constructors ==========================
//

//
// initailize hashtable
//
Hashtable::Hashtable() 
//-------------------------------------------------
// Pre : none
// Post: total count and next overflow are initialized
//-------------------------------------------------
{
	total_count_ = 0;
	next_overflow_ = FIRST_OVERFLOW;
}

//
// ================= Accessors ==========================
//

//
// Get count
//
//-------------------------------------------------
// Pre : none
// Post: count is returned for Hashtable (includes overflow)
//-------------------------------------------------
int Hashtable::Count(void)
{
	return (total_count_);
}

//
// ================= Private Members ==========================
//

//
// Returns tne next overflow area
//
int Hashtable::GetNextOverflow()
//-------------------------------------------------
// Pre : none
// Post:  if overflow not full
//           return value of next open overflow bucket
//        else
//           return -999
//-------------------------------------------------
{
	int return_value;

	if (next_overflow_ > LAST_OVERFLOW)
	{
		return_value = NO_OVERFLOW;
	}
	else
	{
	    return_value = next_overflow_;
	    next_overflow_++;
	}

	return return_value;
}


//
// Returns hashtable index
//
int Hashtable::HashKey(/* IN    */ const STR10 & key)
//-------------------------------------------------
// Pre : none
// Post: return hashtable index
//-------------------------------------------------
{
	return ((key[KEY_POS2] + key[KEY_POS4] + key[KEY_POS6]) % PRIMARY_SIZE);
}


//
// Recursively tries to insert key/data
//
bool Hashtable::InsertKeyData(/* IN    */ int Bucket_number,
							  /* IN    */ const STR10 & key,
							  /* IN    */ const STR20 & data)
//-------------------------------------------------
// Pre : bucket is a valid bucket nubmer 
//       key contains key to insert
//       data contains data to insert
// Post: if table not full key/data is inserted
//          and true is returned
//       else 
//           false is returned
//-------------------------------------------------

{
	bool return_value = true;

	if (!(buckets_[Bucket_number].Insert(key,data)))
	{
		if (buckets_[Bucket_number].Overflow() == OVERFLOW_EMPTY) 
		{
			int overflow_bucket = GetNextOverflow();
			if (overflow_bucket == NO_OVERFLOW)
			{
				return_value = false;
			}
			else
			{
				buckets_[Bucket_number].Overflow(overflow_bucket);
				return_value = InsertKeyData(overflow_bucket, key, data);
			}
		}
		else
		{
			return_value = InsertKeyData(buckets_[Bucket_number].Overflow(), key, data);
		}
	}

	return return_value;
}


//
// recursively searches for key in hashtable
//
bool Hashtable::KeyFound(/* IN    */ const STR10 & key, 
						 /* INOUT */ int & Bucket_number,
						 /* OUT   */ int & Slot_Number,  
						 /* OUT   */ STR20 & data)       
//-------------------------------------------------
// Pre : bucket is a valid bucket nubmer 
//       key contains key to search for
// Post: if key is found
//          bucket_number, slot_number and data
//          contain bucket, slot and data of key
//          true is returned
//       else 
//          bucket, slot and data contain garbage
//          false is returned
//-------------------------------------------------
{
	bool return_value = false;

	if ((buckets_[Bucket_number].HasKey(key, Slot_Number)))
	{
		strcpy(data, *(buckets_[Bucket_number].data(Slot_Number)));
		return_value = true;
	}
	else
	{
		if (buckets_[Bucket_number].Overflow() == OVERFLOW_EMPTY) 
		{
			return_value = false;		
		}
		else
		{
			Bucket_number = buckets_[Bucket_number].Overflow();		
			return_value = KeyFound(key, Bucket_number, Slot_Number, data);
		}
	}

	return return_value;
}

//
// ================= Member Methods ==========================
//


//
// resets hashtable
//
void Hashtable::Clear(void)
//-------------------------------------------------
// Pre : none
// Post: all buckets have been reset
//-------------------------------------------------
{
	for(int bnum =	0; bnum < MAX_BUCKETS; bnum++)
	{

		   buckets_[bnum].Clear();
	}
}



void Hashtable::Generate_Length_Report(/* INOUT */ std::ostream &os) const
//-------------------------------------------------
// Pre : os is valid ostream 
// Post: Length Report is Written to standard output
//-------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();

	int total_bucket_lengths = 0;
	int total_buckets_with_collisions = 0;


	os  << std::left
		<< std::setw(16)
		<< "PRIMARY BUCKETS:"
		<< std::endl
		<< std::endl;

	for(int bnum =	FIRST_PRIMARY; bnum <= LAST_PRIMARY; bnum++)
	{
		os << std::left
		   << std::setw(7)
		   << "Bucket"
		   << std::setw(2)
		   << bnum + 1
		   << std::setw(3)
		   << ": "
		   << buckets_[bnum].Count()
		   << std::endl;
		
		if (buckets_[bnum].Count() > 1)
		{
			total_buckets_with_collisions++;
			total_bucket_lengths += buckets_[bnum].Count();
		}
	}

	os  << std::left
		<< std::setw(16)
		<< std::endl;

	os  << std::left
		<< std::setw(16)
		<< "Average Chain Length:" 
		<< std::setprecision(0)
		<< std::setw(16)
		<< (total_bucket_lengths / total_buckets_with_collisions)
		<< std::endl
		<< std::endl;


    //
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return;
}


//
// Returnss data for passed key
//
bool Hashtable::GetData(/* IN    */ const STR10 & key,
						/* OUT   */ int & Bucket_Number,
						/* OUT   */ int & Slot_Number,
						/* OUT   */ STR20 & data)
//-------------------------------------------------
// Pre:  key contains key to searched for
// Post: if key is found in hashtable
//          bucket will contain the bucket number for key
//          slot will contain the slot number for the key
//          data will contain the data for key
//          true is returned
//       else
//          bucket and slot contain -99 
//          data contains not found message
//          false is returned
//-------------------------------------------------

{
	bool return_value = true;
	Bucket_Number = HashKey(key);

	if (!(KeyFound(key, Bucket_Number, Slot_Number, data)))
	{
		Bucket_Number = -99;
		Slot_Number = -99;
		strcpy(data,RECORD_NOT_FOUND);
		return_value = false;
	}
	else
	{
		Bucket_Number++;
		Slot_Number++;
	}

	return return_value;
}


//
// inserts key/data into hash table
//
bool Hashtable::Insert(/* IN    */ const STR10 & key,
					   /* IN    */ const STR20 & data)
//-------------------------------------------------
// Pre : bucket is a valid bucket nubmer 
//       key contains key to insert
//       data contains data to insert
// Post: if table not full key/data is inserted
//       else message is displayed
//-------------------------------------------------
{
	bool return_value = true;
	int orig_number = HashKey(key);
	int bucket_number = orig_number;

	if (!(InsertKeyData(bucket_number,key,data)))
	{
		std::cerr << std::endl
			      << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
			      << "!! UNABLE TO INSERT INTO HASHTABLE !!" << std::endl
				  << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl
				  << std::endl;
		std::cerr << "Key : " << key << std::endl;
		std::cerr << "Data: " << data << std::endl;
		std::cerr << std::endl;
		return_value = false;
	}
	else
	{
		if (buckets_[orig_number].Overflow() != OVERFLOW_EMPTY)
		{
			buckets_[orig_number]++;
		}

		total_count_++;
	}


	return return_value;
}


//
// ================= Operators ==========================
//

//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs Hashtable to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os, 
						  /* IN    */ const Hashtable &ht)
//-------------------------------------------------------
// Pre : os is valid iostream & ht is valid hashtable
// Post: iostream os contains outputted hashtable
//-------------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();
	


	os  << std::left
		<< std::setw(16)
		<< "PRIMARY BUCKETS:"
		<< std::endl
		<< std::endl;

	for(int bnum =	FIRST_PRIMARY; bnum <= LAST_PRIMARY; bnum++)
	{
		os << std::left
		   << std::setw(7)
		   << "Bucket"
		   << std::setw(2)
		   << bnum + 1
		   << std::setw(3)
		   << ": "
		   << std::endl
		   << ht.buckets_[bnum] 
		   << std::endl;
	}

	os  << std::endl
		<< std::left
		<< std::setw(17)
		<< "OVERFLOW BUCKETS:"
		<< std::endl
		<< std::endl;


	for(int bnum =	FIRST_OVERFLOW; bnum <= LAST_OVERFLOW; bnum++)
	{
		os << std::left
		   << std::setw(7)
		   << "Bucket"
		   << std::setw(2)
		   << bnum + 1
		   << std::setw(3)
		   << ": "
		   << std::endl
		   << ht.buckets_[bnum] 
		   << std::endl;
	}


	os  << std::left
		<< std::setw(16)
		<< std::endl;


    //
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
