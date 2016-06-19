//********************************************************
// File Name   : Stack.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Header file for Stack class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>
#include "List.h"

#ifndef STACK_h
#define STACK_h

//
// --- CONSTANTS -----
// 


class Stack : public List
{

	//
	// -- data members -----
	//
	private:
		NodeType*	pTop_;
	
	// --- private functions ----

	public:
		// --- Constructors ----
		Stack();
	
		// --- Destructor ----
		virtual ~Stack();

		// --- Accessors -----
		long Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total items in Stack is returned
			//-------------------------------------------------

		// --- Mutators -------


		// --- Member Methods ---

		bool IsEmpty(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE Stack is empty 
			//-------------------------------------------------


		bool IsFull(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE out of memory space
			//-------------------------------------------------


		ItemType Pop(void);
			//-------------------------------------------------
			// Pre : NOT IsEmpty
			// Post: Item pointed to by top is removed from 
			//       stack 
			//-------------------------------------------------


		bool Push(/* IN    */ ItemType insertItem );
			//-------------------------------------------------
			// Pre : insertItem is assigned 
			// Post: if Memory available 
			//          New node is pushed on stack
			//       else
			//          IsFull = TRUE && FALSE is returned
			//-------------------------------------------------


		ItemType Top(void);
			//-------------------------------------------------
			// Pre : NOT IsEmpty 
			// Post: Item pointed to by top is returned
			//-------------------------------------------------

};

#endif