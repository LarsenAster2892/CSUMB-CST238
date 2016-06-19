//********************************************************
// File Name   : List.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Header file for Link List class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>
using std::string;

#ifndef LIST_h
#define LIST_h

//
// --- CONSTANTS -----
// 


//
// --- DEFINED TYPES  -----
//


struct ItemType {
	string	key;  
	double	data;
};


struct NodeType;		// Forward declaration, Hidden in Implementation file


class List
{

	//
	// -- data members -----
	//
	private:
		NodeType*	pHead_;
		NodeType*	pCurrent_;
		NodeType*	pPrevious_;
		NodeType*	pTail_;
		long		count_;
		bool		outOfMemory_;
	
	// --- private functions ----

	public:
		// --- Constructors ----
		List();
	
		// --- Destructor ----
		virtual ~List();

		// --- Accessors -----
		long Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total items in list is returned
			//-------------------------------------------------

		// --- Mutators -------


		// --- Member Methods ---
		ItemType CurrentItem(void) const;
			//-------------------------------------------------
			// Pre : NOT IsEmpty && NOT EndOfList()
			// Post: Item pointed to by current_ is returned
	
		void Clear(void);
			//-------------------------------------------------
			// Pre : 
			// Post: All items are deleted from list
			//-------------------------------------------------


		void Delete(void);
			//-------------------------------------------------
			// Pre : NOT IsEmpty && NOT EndOfList()
			// Post: Item pointed to by current_ is deleted
			//       && successor of deleted item is now the 
			//       current item
			//-------------------------------------------------

		bool EndOfList(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE if current_ points to last 
			//       item in list
			//-------------------------------------------------
		bool List::Find(/* IN    */ string Key);
			//-------------------------------------------------
			// Pre : Key is assigned 
			// Post: if key in list 
			//          TRUE is returned 
			//          && current points to node
			//       else
			//          FALSE is returned
			//          && current points to last item in list
			//-------------------------------------------------

		bool InsertAfter(/* IN    */ ItemType insertItem );
			//-------------------------------------------------
			// Pre : insertItem is assigned &&
			//       head != NULL && current != NULL
			// Post: if Memory available 
			//          New node is inserted after current
			//          && current points to node
			//       else
			//          IsFull = TRUE && FALSE is returned
			//-------------------------------------------------

		bool InsertBefore(/* IN    */ ItemType insertItem );
			//-------------------------------------------------
			// Pre : insertItem is assigned &&
			//       head != NULL && current != NULL
			// Post: if Memory available 
			//          New node is inserted after current
			//          && current points to node
			//       else
			//          IsFull = TRUE && FALSE is returned
			//-------------------------------------------------

		bool IsEmpty(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE list is empty 
			//-------------------------------------------------

		bool IsFull(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE out of memory space
			//-------------------------------------------------

		void MoveFirst(void);
			//-------------------------------------------------
			// Pre : none
			// Post: if !IsEmpty() 
			//          current item pointer is set first item
			//       else
			//			current item pointer is set to NULL
			//-------------------------------------------------

		void MoveLast(void);
			//-------------------------------------------------
			// Pre : none
			// Post: if !IsEmpty() 
			//          current item pointer is set last item
			//       else
			//			current item pointer is set to NULL
			//-------------------------------------------------

		void MoveNext(void);
			//-------------------------------------------------
			// Pre : none
			// Post: if Current != Last
			//          current item pointer is set next item
			//       else
			//			current item pointer is set to Last
			//-------------------------------------------------

		bool ReplaceItem(/* IN    */ ItemType replaceItem );
			//-------------------------------------------------
			// Pre : replaceItem is assigned &&
			//       head != NULL && current != NULL
			// Post: if !ISEMPTY() && current != NULL
			//          values of current is replaced by replaceItem
			//          && TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------

};

#endif