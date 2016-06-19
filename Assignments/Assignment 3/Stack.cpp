//********************************************************
// File Name   : Stack.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Class member functions for Queue Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "STACK.H"

//
// ================= Constructors ==========================
//
Stack::Stack() : List()
	//-------------------------------------------------
	// Pre : none
	// Post: top is initialized
	//-------------------------------------------------
{
	pTop_ =  NULL;

}

//
// ================= Destructor ==========================
//
Stack::~Stack() 
	//-------------------------------------------------
	// Pre : none
	// Post: Stack is destructed and cleaned up
	//-------------------------------------------------
{
}



//
// ================= Accessors ==========================
//

//
// Get number of items
//
long Stack::Count()	const
	//-------------------------------------------------
	// Pre : none
	// Post: total items in list is returned
	//-------------------------------------------------
{
	return (List::Count()); 
}


//
// ================= Member Methods ==========================
//


//
// check if Stack is empty
//
bool Stack::IsEmpty(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE Stack is empty 
	//-------------------------------------------------
{

	return (List::IsEmpty());
}

//
// check if out of memory
//
bool Stack::IsFull(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE Stack is full
	//-------------------------------------------------
{

	return (List::IsFull());
}

//
// Remove a item from top of Stack
//
ItemType Stack::Pop(void) 
	//-------------------------------------------------
	// Pre : NOT IsEmpty
	// Post: Item pointed to by top is removed from 
	//       stack 
	//-------------------------------------------------
{
	List::MoveFirst();
	ItemType tempItem = List::CurrentItem();
	List::Delete();
	return (tempItem);
}

//
// Inserts item at top of stack
//
bool Stack::Push(/* IN    */ ItemType insertItem )
	//-------------------------------------------------
	// Pre : insertItem is assigned 
	// Post: if Memory available 
	//          New node is pushed on stack
	//       else
	//          IsFull = TRUE && FALSE is returned
	//-------------------------------------------------

{
	List::MoveFirst();
	return (List::InsertBefore(insertItem));
}

//
// Returns item on top of stack, but item remains on stack
//
ItemType Stack::Top(void) 
	//-------------------------------------------------
	// Pre : NOT IsEmpty
	// Post: Item pointed to by top is returned
	//-------------------------------------------------
{
	List::MoveFirst();
	ItemType tempItem = List::CurrentItem();
	return (tempItem);
}