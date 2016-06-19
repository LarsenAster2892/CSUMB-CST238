//********************************************************
// File Name   : Queue.cpp    
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
#include "Queue.H"

//
// ================= Constructors ==========================
//
Queue::Queue() : List()
	//-------------------------------------------------
	// Pre : none
	// Post: top is initialized
	//-------------------------------------------------
{

}

//
// ================= Destructor ==========================
//
Queue::~Queue() 
	//-------------------------------------------------
	// Pre : none
	// Post: Queue is destructed and cleaned up
	//-------------------------------------------------
{
}



//
// ================= Accessors ==========================
//

//
// Get number of items
//
long Queue::Count()	const
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
// Remove a item from front of Queue
//
ItemType Queue::Dequeue(void) 
	//-------------------------------------------------
	// Pre : NOT IsEmpty
	// Post: Item on at the front of the queue is removed
	//-------------------------------------------------
{
	List::MoveFirst();
	ItemType tempItem = List::CurrentItem();
	List::Delete();
	return (tempItem);
}


//
// Adds item at end of Queue
//
bool Queue::Enqueue(/* IN    */ ItemType insertItem )
	//-------------------------------------------------
	// Pre : insertItem is assigned 
	// Post: if Memory available 
	//          New node added to end Queue
	//       else
	//          IsFull = TRUE && FALSE is returned
	//-------------------------------------------------

{
	List::MoveLast();
	return (List::InsertAfter(insertItem));
}



//
// Returns item at front of Queue, but item remains on Queue
//
ItemType Queue::Front(void) 
	//-------------------------------------------------
	// Pre : NOT IsEmpty
	// Post: Item at front of queue is returned 
	//-------------------------------------------------
{
	List::MoveFirst();
	ItemType tempItem = List::CurrentItem();
	return (tempItem);
}

//
// check if Queue is empty
//
bool Queue::IsEmpty(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE Queue is empty 
	//-------------------------------------------------
{

	return (List::IsEmpty());
}

//
// check if out of memory
//
bool Queue::IsFull(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE Queue is full
	//-------------------------------------------------
{

	return (List::IsFull());
}


