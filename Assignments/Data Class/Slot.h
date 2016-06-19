//********************************************************
// File Name   : Slot.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3 (Original Assignment - 1)
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for Slot class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
#include <iostream>
#include <iomanip>

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

//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A Data type Class 
//
// Base Classes: <none>
//
//===================================================================

class Slot
{
	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		STR20 data_;
		STR10 key_;							  	
		
	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:
		

	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	  public:
		//
		// ============= CONSTRUCTOR =====================
		//
		Slot(/* IN    */ const STR10 key="\0",
			 /* IN    */ const STR20 data="\0");
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~Slot();

	
			 
		//
		// ============= ACCESSORS =====================
		//
		STR20 & data(void);
			//-------------------------------------------------
			// Pre : none
			// Post: data is returned
			//-------------------------------------------------

		STR10 & key(void);
			//-------------------------------------------------
			// Pre : none
			// Post: key is returned
			//-------------------------------------------------


		//
		// ============= MUTATORS =====================
		//
		void data(/* IN    */ const STR20 & new_data);
			//-------------------------------------------------
			// Pre : none
			// Post: data is set to new value
			//-------------------------------------------------

		void key(/* IN    */ const STR10 & new_key);
			//-------------------------------------------------
			// Pre : none
			// Post: key is set to new value
			//-------------------------------------------------


		//
		// ============= MEMBER METHODS =====================
		//
		bool KeyMatch(/* IN    */ const STR10 & test_key);
			//----------------------------------------------------
			// Pre : none
			// Post: key is set to new value
			//-------------------------------------------------



		//
		//========= STREAM FUNCTIONS ==================
		//
		// ---- OUT STREAM ----
		friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
										/* IN    */ const Slot &s);
			//----------------------------------------------------
			// Pre : os is valid iostream & s is valid slot
			// Post: iostream os contains outputted slot
			//-------------------------------------------------

};

	std::ostream & operator<<(std::ostream &os, const Slot &s);

#endif