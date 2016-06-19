//********************************************************
// File Name   : Queue.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Header file for Queue Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>
#include "List.h"

#ifndef QUEUE_h
#define QUEUE_h

//
// --- CONSTANTS -----
// 


class Queue: public List
{

	//
	// -- data members -----
	//
	private:
	
	// --- private functions ----

	public:
		// --- Constructors ----
		Queue();
	
		// --- Destructor ----
		virtual ~Queue();

		// --- Accessors -----
		long Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total items in Queue is returned
			//-------------------------------------------------

		// --- Mutators -------


		// --- Member Methods ---

		ItemType Dequeue(void);
			//-------------------------------------------------
			// Pre : NOT IsEmpty
			// Post: Item at the front of the queue is removed
			//-------------------------------------------------

		bool Enqueue(/* IN    */ ItemType insertItem );
			//-------------------------------------------------
			// Pre : insertItem is assigned 
			// Post: if Memory available 
			//          New node is added to back of Queue
			//       else
			//          IsFull = TRUE && FALSE is returned
			//-------------------------------------------------

		ItemType Front(void);
			//-------------------------------------------------
			// Pre : NOT IsEmpty 
			// Post: Item pointed to by Front is returned
			//-------------------------------------------------

		bool IsEmpty(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE Queue is empty 
			//-------------------------------------------------


		bool IsFull(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE out of memory space
			//-------------------------------------------------

};

#endif