//********************************************************
// File Name   : DataSlot.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for DataSlot Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "Data.h"
#include "Slot.h"
#include <string>

//
// --- USING STATEMENTS -----
// 
using std::string;

#ifndef DATASLOT_h
#define DATASLOT_h


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A Data type Class 
//
// Base Classes: Data and Slot
//
//===================================================================

class DataSlot : public Data, public Slot
{

	private:
	//
	// -- data members -----
	//

	//---------------------------------------------------
	// Since this is a drived class
	// all data members are present the base class
	//---------------------------------------------------

	// Slot DataItem_;
	

	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		DataSlot();


		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~DataSlot();
		
		//
		// ============= COPY CONSTRUCTOR =====================
		//
		DataSlot(/* IN    */ DataSlot & copyItem); 
			//-------------------------------------------------
			// Pre : copyItem is Assigned
			// Post: (*this) is assigned values of copyItem
			//-------------------------------------------------

		//
		// ============= ACCESSORS =====================
		//
		STR20 & data(void);
			//-------------------------------------------------
			// Pre : none
			// Post: data is returned
			//-------------------------------------------------

		STR10 & Get(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: return item key values
			// Notes:  While this method is the same as the key()
			//         it is required by base class
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

		void Set(/* IN    */ Slot & dataItem);
			//-------------------------------------------------
			// Pre : dataItem is assigned
			// Post: set new value for Items
			//-------------------------------------------------

		
		//
		//========= OPERATOR FUNCTIONS ==================
		//
		bool operator<  (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is greater than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator>  (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is less than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator== (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is equal to (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------


		//
		//========= STREAM FUNCTIONS ==================
		//
		// ---- OUT STREAM ----
	    friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
										 /* IN    */ const DataSlot &ds);
			//----------------------------------------------------
			// Pre : os is valid iostream & ds is valid DataSlot
			// Post: iostream os contains outputted DataSlot
			//-------------------------------------------------

};

	std::ostream & operator<<(std::ostream &os, const DataSlot &ds);


#endif