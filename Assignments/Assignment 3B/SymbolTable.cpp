//********************************************************
// File Name   : SymbolTable.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Class member functions for SymbolTable Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "SymbolTable.H"

//
// ================= Constructors ==========================
//
SymbolTable::SymbolTable() : symbolList_()
	//-------------------------------------------------
	// Pre : none
	// Post: top is initialized
	//-------------------------------------------------
{

}

//
// ================= Destructor ==========================
//
SymbolTable::~SymbolTable() 
	//-------------------------------------------------
	// Pre : none
	// Post: SymbolTable is destructed and cleaned up
	//-------------------------------------------------
{
}



//
// ================= Accessors ==========================
//

//
// Get number of items
//
long SymbolTable::Count()	const
	//-------------------------------------------------
	// Pre : none
	// Post: total items in list is returned
	//-------------------------------------------------
{
	return (symbolList_.Count()); 
}


//
// ================= Member Methods ==========================
//

//
// Adds item at end of SymbolTable
//
bool SymbolTable::Add(/* IN    */ string symbolName,
		              /* IN    */ double symbolValue )
	//-------------------------------------------------
	// Pre : SymbolName is assigned 
	// Post: if Memory available 
	//          SymbolName and value are added to table
	//          and TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------

{
	ItemType insertItem;
	insertItem.key = symbolName;
	insertItem.data = symbolValue;

	symbolList_.MoveLast();
	return (symbolList_.InsertAfter(insertItem));
}

//
// Clear all items from SymbolTable
//
void SymbolTable::Clear(void)
	//-------------------------------------------------
	// Pre : none
	// Post: SymbolTable is empty 
	//-------------------------------------------------
{

	symbolList_.Clear();
}


//
// Returns current Symbol
//

bool SymbolTable::CurrentSymbol(/* OUT    */ string & symbolName,
			                    /* OUT    */ double & symbolValue) const
	//-------------------------------------------------
	// Pre : !IsEmpty 
	// Post: if not IsEmpty
	//			SymbolName is set to name
	//          SymbolValue is set to value
	//          and TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------

{
	bool returnValue = symbolList_.IsEmpty();

	if (!returnValue)
	{
		ItemType tempItem = symbolList_.CurrentItem();
		symbolName  = tempItem.key[0];
		symbolValue = tempItem.data;

	}
	return (!returnValue);
}

//
// Remove a symbol from SymbolTable
//
bool SymbolTable::Delete(/* IN    */ string	 symbolName) 
	//-------------------------------------------------
	// Pre : SymbolName is assigned 
	// Post: if symbolname in symboltable
	//          SymbolName and value are deleted from table
	//          and TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------
{
	bool returnValue = symbolList_.Find(string(symbolName));

	if (returnValue)
	{
		symbolList_.Delete();
	}
	return (returnValue);
}


//
// Get value of symbol
//

bool SymbolTable::GetValue(/* IN    */ string   symbolName,
		                   /* OUT   */ double & symbolValue)
	//-------------------------------------------------
	// Pre : SymbolName is assigned 
	// Post: if symbolname in symboltable
	//          SymbolValue is set to value
	//          and TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------
{
	bool returnValue = symbolList_.Find(symbolName);

	if (returnValue)
	{
		ItemType tempItem = symbolList_.CurrentItem();
		symbolValue = tempItem.data;
	}
	
	return (returnValue);
}



//
// check if SymbolTable is empty
//
bool SymbolTable::IsEmpty(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE SymbolTable is empty 
	//-------------------------------------------------
{

	return (symbolList_.IsEmpty());
}

//
// check if out of memory
//
bool SymbolTable::IsFull(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE SymbolTable is full
	//-------------------------------------------------
{

	return (symbolList_.IsFull());
}

//
// Set value of symbol
//

bool SymbolTable::SetValue(/* IN    */ string   symbolName,
		                   /* IN    */ double   symbolValue)
	//-------------------------------------------------
	// Pre : SymbolName is assigned 
	// Post: if symbolname in symboltable
	//          value is set to SymbolValue
	//          and TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------
{
	bool returnValue = symbolList_.Find(symbolName);

	if (returnValue)
	{
		ItemType tempItem = symbolList_.CurrentItem();
		tempItem.data = symbolValue;
		symbolList_.ReplaceItem(tempItem);
	}
	
	return (returnValue);
}

//
// move to first symbol
//
void SymbolTable::MoveFirst(void)
	//-------------------------------------------------
	// Pre : none
	// Post: set Current to first Item
	//-------------------------------------------------
{

	symbolList_.MoveFirst();
}

//
// move to Last symbol
//
void SymbolTable::MoveLast(void)
	//-------------------------------------------------
	// Pre : none
	// Post: set Current to first Item
	//-------------------------------------------------
{

	symbolList_.MoveLast();
}

//
// move to next symbol
//
void SymbolTable::MoveNext(void)
	//-------------------------------------------------
	// Pre : !IsEmpty && current item != Last
	// Post: if !isEmpty
	//          if current Item != last
	//             current points to next symbol
	//          else
	//             current points to last symbol
	//       
	//-------------------------------------------------
{
	if (!symbolList_.IsEmpty())
	{
		
		symbolList_.MoveNext();
	}
}