//********************************************************
// File Name   : DataContainer.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Header file for DataContainer Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "Data.h"


#ifndef DATACONTAINER_h
#define DATACONTAINER_h
//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A DataContainer Class 
//
// Base Classes: <none>
//
//===================================================================

//
// --- CONSTANTS -----
// 
const int DEFAULT_SIZE = 10;		// The number of elements in the arrary

class DataContainer
{
	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
	//
	// Since this is an Abstract Base Class,
	//  there are no data private data members....

	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:
	//
	// -- Protected data members -----
	//
	// Since this is an Abstract Base Class,
	//  using protected data members will all drived classes
	//  the ability to use data members as needed.
	//
	//	
		int	   SizeDC_;
		int    NextItem_;
		Data ** DataTable_;

	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		DataContainer(/* IN    */ int NumberDataItems = DEFAULT_SIZE);
	
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~DataContainer();

		//
		// ============= ACCESSORS =====================
		//
		int SizeDC(void);
			//-------------------------------------------------
			// Pre : SizeDC_ is assigned
			// Post: SizeDC is returned
			//-------------------------------------------------

	    virtual Data & GetItem(/* IN    */ int ItemNumber) const;
			//-------------------------------------------------
			// Pre : ItemNumber is assigned 
			//       and 0 <= ItemNumber <= SizeDC_
			// Post: Data Object at DataTable[ItemNumber] is returned
			//-------------------------------------------------
		

		//
		// ============= MUTATORS =====================
		//
	    virtual bool AddItem(/* IN    */ Data & inItem);
			//-------------------------------------------------
			// Pre : !IsFull
			// Post: if !IsFull
			//          inItem is Add to DataType
			//          and true is returned
			//       else
			//          false is returned
			//-------------------------------------------------

	    virtual void Clear(void) = 0;
			//-------------------------------------------------
			// Pre : <none>
			// Post: DataTable is Cleared and SizeDC is reset
			//-------------------------------------------------

		// 
		//
		// ============= MEMBER METHODS =====================
		//

	    bool IsFull(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: if NextItem_ > SizeDC_
			//          returns true
			//       else
			//          returns false
			//-------------------------------------------------

		
		virtual void SwapItems(/* IN    */ int ItemNumberA,
							   /* IN    */ int ItemNumberB) = 0;
			//-------------------------------------------------
			// Pre : ItemNumberA and ItemNumberB are assigned 
			//       and 0 <= ItemNumberA <= SizeDC_
			//       and 0 <= ItemNumberB <= SizeDC_
			// Post: Items in DataTable at ItemNumberA and
			//       ItemNumberB are swapped
			//-------------------------------------------------

		virtual void PrintItems(void) = 0;
			//-------------------------------------------------
			// Pre : <none> 
			// Post: Items in DataTable have been outputted to 
			//       the output stream
			//-------------------------------------------------
	    

};

#endif