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
#include "DataContainer.h"
#include "DataSlot.h"

#ifndef DATACONTAINERSLOT_h
#define DATACONTAINERSLOT_h
//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A DataContainer type Class 
//
// Base Classes: DataContainer and DataSlot
//
//===================================================================

class DataContainerSlot : public DataContainer, public DataSlot
{

	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		//
		// -- data members -----
		//
		// Declaration of an array of pointer to DataSlot types
		DataSlot ** DataTable_;		
	
		
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
		DataContainerSlot(/* IN    */ int NumberDataItems = DEFAULT_SIZE);
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~DataContainerSlot();

		//
		// ============= ACCESSORS =====================
		//

	    virtual DataSlot & GetItem(/* IN    */ int ItemNumber) const;
			//-------------------------------------------------
			// Pre : ItemNumber is assigned 
			//       and 0 <= ItemNumber <= SizeDC_
			// Post: Data Object at DataTable[ItemNumber] is returned
			//-------------------------------------------------
		
		//
		// ============= MUTATORS =====================
		//
	    virtual bool AddItem(/* IN    */ DataSlot & inItem);
			//-------------------------------------------------
			// Pre : !IsFull
			// Post: if !IsFull
			//          inItem is Add to DataType
			//          and true is returned
			//       else
			//          false is returned
			//-------------------------------------------------


		// 
		//
		// ============= MEMBER METHODS =====================
		//

	    void Clear(void);
			//-------------------------------------------------
			// Pre : <none>
			// Post: DataTable is Cleared and SizeDC is reset
			//-------------------------------------------------

		void SwapItems(/* IN    */ int ItemNumberA,
			           /* IN    */ int ItemNumberB);
			//-------------------------------------------------
			// Pre : ItemNumberA and ItemNumberB are assigned 
			//       and 0 <= ItemNumberA <= SizeDC_
			//       and 0 <= ItemNumberB <= SizeDC_
			// Post: Items in DataTable at ItemNumberA and
			//       ItemNumberB are swapped
			//-------------------------------------------------

		virtual void PrintItems(void);
			//-------------------------------------------------
			// Pre : <none> 
			// Post: Items in DataTable have been outputted to 
			//       the output stream
			//-------------------------------------------------


};

#endif