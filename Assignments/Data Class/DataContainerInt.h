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
#include "DataInt.h"

#ifndef DATACONTAINERINT_h
#define DATACONTAINERINT_h

//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A DataContainer type Class 
//
// Base Classes: DataContainer and DataInt
//
//===================================================================

class DataContainerInt : public DataContainer, public DataInt
{


	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
		//
		// -- data members -----
		//
		// Declaration of an array of pointer to DataInt types
		DataInt ** DataTable_;		
	
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
		DataContainerInt(/* IN    */ int NumberDataItems = DEFAULT_SIZE);
	
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~DataContainerInt();


		//
		// ============= ACCESSORS =====================
		//

	    virtual DataInt & GetItem(/* IN    */ int ItemNumber) const;
			//-------------------------------------------------
			// Pre : ItemNumber is assigned 
			//       and 0 <= ItemNumber <= SizeDC_
			// Post: Data Object at DataTable[ItemNumber] is returned
			//-------------------------------------------------
		

		//
		// ============= MUTATORS =====================
		//
	    virtual bool AddItem(/* IN    */ DataInt & inItem);
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