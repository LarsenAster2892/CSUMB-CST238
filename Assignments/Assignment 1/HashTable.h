//********************************************************
// File Name   : HashTable.h       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Header file for HashTable class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

#ifndef HASHTABLE_h
#define HASHTABLE_h
//
//  ----  INCLUDES ------
#include "BUCKET.H"

//
// --- CONSTANTS -----
//

const int   FIRST_OVERFLOW = 20;

const int   FIRST_PRIMARY = 0;

const int   KEY_POS2 = 2 - 1;

const int   KEY_POS4 = 4 - 1;

const int   KEY_POS6 = 6 - 1;

const int   LAST_OVERFLOW = 29;

const int   LAST_PRIMARY = 19;

const int   MAX_BUCKETS = 30;

const int   NO_OVERFLOW = -999;

const int   PRIMARY_SIZE = 20;

const STR20 RECORD_NOT_FOUND = "Record not found\0";

class Hashtable
{
  private:
	Bucket buckets_[MAX_BUCKETS + 1];							  	

	int    next_overflow_;

	int    total_count_;	
	

	// --- private functions ----
	int  GetNextOverflow();
	
	int  HashKey(/* IN    */ const STR10 & key);

	bool InsertKeyData(/* IN    */ int Bucket_number,
		               /* IN    */ const STR10 & key,
					   /* IN    */ const STR20 & data);

	bool KeyFound(/* IN    */ const STR10 &  key,
		          /* INOUT */ int & Bucket_number,
				  /* OUT   */ int & Slot_Number,
				  /* OUT   */ STR20 & data);

  public:
    // --- Constructors ----
    Hashtable();
	
	// --- Accessors -----
	int  Count(void);

	// --- Mutators -------


	// --- Member Methods ---
	void Clear(void);

	bool GetData(/* IN    */ const STR10 & key,
		         /* OUT   */ int & Bucket_number,
				 /* OUT   */ int & Slot_Number,
				 /* OUT   */ STR20 & data);
    
	bool Insert(/* IN    */ const STR10 & key,
		        /* IN    */ const STR20 & data);
	

	void Generate_Length_Report(/* INOUT */ std::ostream &os) const;

	// -- operators --


	// -- stream functions ---
	friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
	                                 /* IN    */ const Hashtable &ht);

};

	std::ostream & operator<<(std::ostream &os, const Hashtable &ht);

#endif