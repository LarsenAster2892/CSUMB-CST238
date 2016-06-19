//********************************************************
// File Name   : Data.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for Data Abstract Base Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 

#ifndef DATA_h
#define DATA_h


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class (ABC)
//
//
//===================================================================

class Data
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		
		
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
		Data();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~Data();


		//
		//========= OPERATOR FUNCTIONS ==================
		//
		virtual bool operator<  (/* IN    */ Data & dItem) = 0;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is greater than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		virtual bool operator>  (/* IN    */ Data & dItem) = 0;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is less than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------


		virtual bool operator== (/* IN    */ Data & dItem) = 0;
			//-----------------------------------------------------------
			// Pre : dItem is assigned and is of type DataSlot
			// Post: if dItem key is equal to (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

};

#endif