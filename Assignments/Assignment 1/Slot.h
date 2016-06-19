//********************************************************
// File Name   : Slot.h       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Header file for Slot class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

#ifndef SLOT_h
#define SLOT_h
//
// --- CONSTANTS -----
// 
const int DATASIZE = 20;

const int KEYSIZE = 10;

const char NULLDATA = '\0';

const char NULLKEY = '\0';

//
// --- DEFINED TYPES  -----
//
typedef char STR10[KEYSIZE + 1];

typedef char STR20[DATASIZE + 1];

class Slot
{
  private:
    STR20 data_;
	STR10 key_;							  	

	
	// --- private functions ----

  public:
    // --- Constructors ----
    Slot(/* IN    */ const STR10 key="\0",
		 /* IN    */ const STR20 data="\0");
	
	// --- Accessors -----
	STR20 * data(void);

	STR10 * key(void);


	// --- Mutators -------
	void data(/* IN    */ const STR20 & new_data);

	void key(/* IN    */ const STR10 & new_key);


	// --- Member Methods ---
    bool KeyMatch(/* IN    */ const STR10 & test_key);




	// -- stream functions ---
	friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
									 /* IN    */ const Slot &s);

};

	std::ostream & operator<<(std::ostream &os, const Slot &s);

#endif