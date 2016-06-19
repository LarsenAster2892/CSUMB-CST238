//********************************************************
// File Name   : Bucket.h       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Header file for Bucket class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

#ifndef BUCKET_h
#define BUCKET_h
//
//  ----  INCLUDES ------
//
#include "SLOT.H"
//
// --- CONSTANTS -----
// 
const int MAX_SLOTS = 3;

const int OVERFLOW_EMPTY = -1;

class Bucket
{
  private:
	
	int  count_;
    
	int  overflow_;

	Slot slots_[MAX_SLOTS];							  	
	
	// --- private functions ----

  public:
    // --- Constructors ----
    Bucket();
	
	// --- Accessors -----
	int    Count(void) const;

	STR20* data(/* IN    */ int slot_number);
	
	STR10* key(/* IN    */ int slot_number);

	int    Overflow(void);



	// --- Mutators -------
	void Count(int new_count);

	void data(/* IN    */ int slot_number, 
		      /* IN    */ const STR20 & new_data);

	void key(/* IN    */ int slot_number, 
	         /* IN    */ const STR10 & new_key);

	void Overflow(/* IN    */ int new_overflow);


	// --- Member Methods ---
    void Clear(void);

	bool HasKey(/* IN    */ const STR10 & key, 
		        /* OUT   */ int & slot_number);

	bool Insert(/* IN    */ const STR10 &  key, 
		        /* IN    */ const STR20 & data);

	// -- operators --
    int operator++(int);

	// -- stream functions ---
	friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
		                             /* IN    */ const Bucket &b);

};

	std::ostream & operator<<(std::ostream &os, const Bucket &b);

#endif