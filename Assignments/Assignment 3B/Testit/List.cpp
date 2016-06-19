//********************************************************
// File Name   : List.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Class member functions for List Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "LIST.H"
using std::string;

typedef	NodeType*	NodePtr;	

struct NodeType {
	ItemType	Item;
	NodePtr		pNext;
};

//
// ================= Constructors ==========================
//

List::List()
	//-------------------------------------------------
	// Pre : none
	// Post: head, tail, current, previous, count
	//       and outOfMemory are initialized
	//-------------------------------------------------
{
	pHead_ = pTail_ = pCurrent_ = pPrevious_ = NULL;
	count_ = 0;
	outOfMemory_ = false;

}

//
// ================= Destructor ==========================
//

List::~List()
	//-------------------------------------------------
	// Pre : none
	// Post: all allocated store for list has been 
	//       deallocated
	//-------------------------------------------------
{
	Clear();
}


//
// ================= Accessors ==========================
//

//
// Get number of items
//
long List::Count()	const
	//-------------------------------------------------
	// Pre : none
	// Post: total items in list is returned
	//-------------------------------------------------
{
	 return (count_); 
}




//
// ================= Member Methods ==========================
//


//
// Remove all items from list
//
void List::Clear(void)
	//-------------------------------------------------
	// Pre : none
	// Post: All items are deleted
	//       && IsEmpty is true
	//-------------------------------------------------
{
	pCurrent_ = pHead_;
	while ( !IsEmpty() )
	{
		Delete();
	}
}

//
// get item pointed to by current
//
ItemType List::CurrentItem(void) const
	//-------------------------------------------------
	// Pre : NOT IsEmpty && NOT EndOfList()
	// Post: Item pointed to by current_ is returned
	//-------------------------------------------------
{
	ItemType returnItem;
	
	returnItem.key = pCurrent_->Item.key;
	returnItem.data = pCurrent_->Item.data;

	return (returnItem);
}

//
// delete item pointed to by current
//
void List::Delete(void)
	//-------------------------------------------------
	// Pre : NOT IsEmpty && NOT EndOfList()
	// Post: Item pointed to by current_ is deleted
	//       && successor of deleted item is now the 
	//       current item
	//-------------------------------------------------
{
	NodePtr temp = pCurrent_;

	if (!IsEmpty())
	{
		if (pCurrent_ == pHead_)
		{
			pHead_ = pCurrent_ = pHead_->pNext;
			pPrevious_ = NULL;
		}
		else
		{
			if (pCurrent_ == pTail_)
			{
				pTail_ = pCurrent_ = pPrevious_;
				pPrevious_ = pHead_;
				while (pPrevious_->pNext !=  pCurrent_)
				{
					pPrevious_ = pPrevious_->pNext;
				}
			}
			else
			{
				pPrevious_->pNext = pCurrent_ = pCurrent_->pNext;
			}
		}
		
		delete temp;
		count_--;
	}
	else
	{
		pCurrent_ = pTail_ = NULL;
	}

}

//
// check for End Of List
//
bool List::EndOfList(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE if current_ points to last 
	//       item in list
	//-------------------------------------------------
{

	return (pCurrent_ == pTail_);
}

//
// Look for Item list List
//
bool List::Find(/* IN    */ string Key)
	//-------------------------------------------------
	// Pre : Key is assigned 
	// Post: if key in list 
	//          TRUE is returned 
	//          && current points to node
	//       else
	//          FALSE is returned
	//          && current points to last item in list
	//-------------------------------------------------
{
	bool return_value = false;

	if (!IsEmpty())
	{
		pCurrent_ = pHead_;
		while ( !(pCurrent_->Item.key != Key ) && (pCurrent_ != pTail_) )
		{
			pCurrent_ = pCurrent_->pNext;
		}
		return_value = (pCurrent_->Item.key == Key );
	}

	return (return_value);
}


bool List::InsertAfter(/* IN    */ ItemType insertItem )
	//-------------------------------------------------
	// Pre : insertItem is assigned &&
	//       head != NULL && current != NULL
	// Post: if Memory available 
	//          New node is inserted after current
	//          && current points to node
	//       else
	//          IsFull = TRUE && FALSE is returned
	//-------------------------------------------------
{
	NodePtr pNewItem = new NodeType;
	
	if (pNewItem == NULL)
		outOfMemory_ = true;
	else
	{
		pNewItem->Item.key = insertItem.key;
		pNewItem->Item.data = insertItem.data;
		
		if (!IsEmpty()) 
		{
			pNewItem->pNext = pCurrent_->pNext;
			pCurrent_->pNext = pNewItem;
			pPrevious_ = pCurrent_;

			if (pCurrent_ == pTail_)
			{
				pCurrent_ = pTail_ = pNewItem;
			}
			else
			{
				pCurrent_ = pNewItem;
			}

		}
		else
		{
			pNewItem->pNext = NULL;
			pCurrent_ = pHead_ = pTail_ = pNewItem;
		}


		count_++;
	}
	
	return (!outOfMemory_);

}


bool List::InsertBefore(/* IN    */ ItemType insertItem )
	//-------------------------------------------------
	// Pre : insertItem is assigned 
	// Post: if Memory available 
	//          New node is inserted before current 
	//          && current points to node
	//       else
	//          IsFull = TRUE && FALSE is returned
	//-------------------------------------------------
{
	NodePtr pNewItem = new NodeType;

	if (pNewItem == NULL)
		outOfMemory_ = true;
	else
	{
		pNewItem->Item.key = insertItem.key;
		pNewItem->Item.data = insertItem.data;
		
		pNewItem->pNext = pCurrent_;

		if (pCurrent_ == pHead_)
		{
			//pHead_ = (pHead_ = NULL ? (pTail_ = pNewItem) : pNewItem);
			if (pHead_ == NULL)  // List is empty
			{
				pHead_ = pTail_ = pNewItem;
			}
			else
			{
				pHead_ = pNewItem;
			}
			pPrevious_ = NULL;
		}
		else
		{
			pPrevious_ ->pNext = pNewItem;
		}

		pCurrent_ = pNewItem;
		count_++;
	}

	return (!outOfMemory_);
}



//
// check if list is empty
//
bool List::IsEmpty(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE list is empty 
	//-------------------------------------------------
{

	return (pHead_ == NULL);
}

//
// check if out of memory
//
bool List::IsFull(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: returns TRUE list is full
	//-------------------------------------------------
{

	return (outOfMemory_);
}

void List::MoveFirst(void)
	//-------------------------------------------------
	// Pre : none
	// Post: if !IsEmpty() 
	//          current item pointer is set first item
	//       else
	//			current item pointer is set to NULL
	//-------------------------------------------------
{

	pCurrent_ = pHead_;
}


void List::MoveLast(void)
	//-------------------------------------------------
	// Pre : none
	// Post: if !IsEmpty() 
	//          current item pointer is set last item
	//       else
	//			current item pointer is set to NULL
	//-------------------------------------------------

{

	pCurrent_ = pTail_;
}


void List::MoveNext(void)
	//-------------------------------------------------
	// Pre : none
	// Post: if Current != Last
	//          current item pointer is set next item
	//       else
	//			current item pointer is set to Last
	//-------------------------------------------------

{

	if (pCurrent_ != pTail_)
	{
		pCurrent_ = pCurrent_->pNext;
	}
}

bool List::ReplaceItem(/* IN    */ ItemType replaceItem )
	//-------------------------------------------------
	// Pre : replaceItem is assigned &&
	//       head != NULL && current != NULL
	// Post: if !ISEMPTY() && current != NULL
	//          values of current is replaced by replaceItem
	//          && TRUE is returned
	//       else
	//          FALSE is returned
	//-------------------------------------------------

{
	bool returnValue; 
	
	if ((pCurrent_ == NULL) || IsEmpty())
		returnValue = false;
	else
	{
		pCurrent_->Item.key = replaceItem .key;
		pCurrent_->Item.data = replaceItem .data;
		returnValue = true;		
	}
	
	return (returnValue);

}

