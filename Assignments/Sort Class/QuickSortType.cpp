//***********************************************************************
// File Name   : QuickSortType.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Class member functions for QuickSortType Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "QuickSortType.h"

//
// ================= Constructors ==========================
//
QuickSortType::QuickSortType(/* IN    */ SortOrderType SortOrder): SortType(SortOrder)
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
}


//
// ================= Destructor ==========================
//
QuickSortType::~QuickSortType()
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
void QuickSortType::Sort(/* INOUT */ DataContainer & sortDC)
	//-------------------------------------------------
	// Pre : Data_ is assigned
	// Post: Data_[0..Last] are sorted
	//-------------------------------------------------
{
	pDC_ = & sortDC;
	if (SortType::SortAscending()) 
	{
		QSort(0, pDC_->SizeDC() - 1);
	}
	else
	{
		QSortDescending(0, pDC_->SizeDC() - 1);
	}
}


//----------------------------------------------------------------
// Quicksort Main Routine
// Best case O(NlogN) 
// Worst case O(N^2) 
// Average case O(NlogN) 
//----------------------------------------------------------------

void QuickSortType::QSort (/* IN    */ int start,
						   /* IN    */ int finish)
	//-------------------------------------------------
	// Pre : start and finish are assigned
	//       and pDC_[start..finish] is assigned
	// Post: pDC_[start..finish] are sorted
	//-------------------------------------------------
{
	int left = start,
		right = finish;
	
	Data * pPivot = & pDC_->GetItem((start+finish)/2);
	
	//std::cout << "BEGIN OF ROUTINE " << std::endl; 
	//std::cout << " Start = "    << start
	//	      << " finish = "   << finish
	//		  << " pivot = "    << (start+finish)/2
	//		  << " left = "     << left
	//		  << " right = "    << right
	//		  << std::endl;
 //   pDC_->PrintItems();
	
	while (left < right)
	{
		
		// find left candidate
		while (pDC_->GetItem(left) < (*pPivot))
		{
			//std::cout << " left < (*pPivot))"    << std::endl;
			
			left++;
		}
		//find right candidate
		while (pDC_->GetItem(right) > (*pPivot))
		{
			//std::cout << " right > (*pPivot))"    << std::endl;
			
			right--;
		}

		if (left < right)
		{
			// Swap 
			//std::cout << " Swap left = " << left << " Right = " << right << std::endl;
			pDC_->SwapItems(left,right);
		}

		//std::cout << "END OF LOOP PASS " << std::endl; 
		//std::cout << " Start = "    << start
		//		<< " finish = "   << finish
		//		<< " pivot = "    << (start+finish)/2
		//		<< " left = "     << left
		//		<< " right = "    << right
		//		<< std::endl;
	 
		//pDC_->PrintItems();

	} // while left <= right

	left++;
	right--;
		
	if (start < right)
	{
		QSort(start,right);
	}

	//std::cout << "END OF FIRST SORT " << std::endl; 
	//std::cout << " Start = "    << start
	//	      << " finish = "   << finish
	//		  << " pivot = "    << (start+finish)/2
	//		  << " left = "     << left
	//		  << " right = "    << right
	//		  << std::endl;
	//
	//pDC_->PrintItems();

	if (left < finish)
	{
		QSort(left,finish);
	}
	//std::cout << "END OF ROUTINE " << std::endl; 
	//std::cout << " Start = "    << start
	//	      << " finish = "   << finish
	//		  << " pivot = "    << (start+finish)/2
	//		  << " left = "     << left
	//		  << " right = "    << right
	//		  << std::endl;
	//
	//pDC_->PrintItems();
}


//----------------------------------------------------------------
// Quicksort Main Routine for sorting Descending
// Best case O(NlogN) 
// Worst case O(N^2) 
// Average case O(NlogN) 
//----------------------------------------------------------------

void QuickSortType::QSortDescending (/* IN    */ int start,
						             /* IN    */ int finish)
	//-------------------------------------------------
	// Pre : start and finish are assigned
	//       and pDC_[start..finish] is assigned
	// Post: pDC_[start..finish] are sorted
	//-------------------------------------------------
{
	int left = start,
		right = finish;
	
	Data * pPivot = & pDC_->GetItem((start+finish)/2);

	while (left < right)
	{
		//Add descending sort order
		
		// find left candidate
		while (pDC_->GetItem(left) > (*pPivot))
		{
			left++;
		}
		//find right candidate
		while (pDC_->GetItem(right) < (*pPivot))
		{
			
			right--;
		}

		if (left < right)
		{
			// Swap 
			pDC_->SwapItems(left,right);
		}


	} // while left <= right

	left++;
	right--;

	if (start < right)
	{
		QSortDescending(start,right);
	}

	if (left < finish)
	{
		QSortDescending(left,finish);
	}

}

