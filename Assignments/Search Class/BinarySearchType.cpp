//***********************************************************************
// File Name   : BinarySearchType.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for BinarySearchType Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "BinarySearchType.h"

//
// ================= Constructors ==========================
//
BinarySearchType::BinarySearchType(): SearchType()
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
}


//
// ================= Destructor ==========================
//
BinarySearchType::~BinarySearchType()
	//-------------------------------------------------
	// Pre : none
	// Post: Class is destructed and cleaned up
	//-------------------------------------------------
{
}

//
// ================= Member Methods ==========================
//
//
// Sort Data
//
int BinarySearchType::Search(/* IN    */ DataContainer & searchDC,
				            /* IN    */ Data & searchValue)
	//-------------------------------------------------
	// Pre : Data_ is assigned
	// Post: Data_[0..Last] are sorted
	//-------------------------------------------------
{
	pDC_ = & searchDC;
	pValue_ = & searchValue;

	return (BinarySearch(0, pDC_->SizeDC() - 1));
}


//void BinarySearch(const int A[], int First start, int Last finish,
//                  int Value, int& Index)

int BinarySearchType::BinarySearch(/* IN    */ int First,
			                       /* IN    */ int Last)
    //-------------------------------------------------
	// Pre : First, Last and Value are assigned
	//       and 0 <= First, Last <= SIZE-1, 
    //           where SIZE is the maximum size of the array,
	//       and pDC_[First..Last] and pValue_ are assigned
	// Post: pDC_ has been search for Value point to by pValue_
	//       if Value is found
	//          returns index within DataContainer
	//       else
	//			returns -1
	//-------------------------------------------------

{
  int Index;

  if (First > Last)
  {
      Index = -1;      // Value not in original DataContainer
  }
  else
  {
      int Mid = (First + Last)/2;

      //if (Value == A[Mid])
	  if ((*pValue_) == pDC_->GetItem(Mid))
	  {
        Index = Mid;       // Value found at DataContainer[Mid]
	  }		
     // else if (Value < A[Mid])
	  else if ((*pValue_) < pDC_->GetItem(Mid))
	  {
        //BinarySearch(A, First, Mid-1, Value, Index);  // X
        Index = BinarySearch(First, Mid-1);  // X
	  }		

      else
	  {
        //BinarySearch(A, Mid+1, Last, Value, Index);   // Y
        Index = BinarySearch(Mid+1, Last);   // Y
	  }

  }  // end else

  return (Index);

}  // end BinarySearch

