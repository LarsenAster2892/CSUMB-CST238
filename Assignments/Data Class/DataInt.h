//********************************************************
// File Name   : DataInt.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for DataInt Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "Data.h"
#include "Slot.h"


#ifndef DATAINT_h
#define DATAINT_h


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A Data type Class 
//
// Base Classes: Data and int (primary) 
//
//===================================================================


class DataInt : public Data
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		int DataItem_;
		
		
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
		DataInt();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~DataInt();



		//
		// ============= ACCESSORS =====================
		//
		int  Get(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: return item values
			//-------------------------------------------------
		
		//
		// ============= MUTATORS =====================
		//
		void Set(/* IN    */ int dataItem);
			//-------------------------------------------------
			// Pre : dataItem is assigned
			// Post: set new value for Items
			//-------------------------------------------------

		//
		//========= OPERATOR FUNCTIONS ==================
		//
		bool operator<  (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataInt
			// Post: if dItem key is greater than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator>  (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataIntt
			// Post: if dItem key is less than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator== (/* IN    */ Data & dItem) ;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataInt
			// Post: if dItem key is equal to (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		operator int();
			//-----------------------------------------------------------
			// Pre : <none>
			// Post: returns DataItem_ as integer
			//----------------------------------------------------------

		//
		//========= STREAM FUNCTIONS ==================
		//
		// ---- IN STREAM ----
		//
		friend std::istream & operator>>(/* INOUT */ std::istream &is, 
										 /* OUT   */ DataInt &di);
		//
		// ---- OUT STREAM ----
		//
	    friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
										 /* IN    */ const DataInt &di);
			//----------------------------------------------------
			// Pre : os is valid iostream & ds is valid DataInt
			// Post: iostream os contains outputted DataSlot
			//-------------------------------------------------
};

	
	std::istream & operator>>(std::istream &is, DataInt &di);

	std::ostream & operator<<(std::ostream &os, const DataInt &di);



#endif