//********************************************************
// File Name   : Slot Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Used to test Slot Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "LIST.H"
// ------ Functions -------


// ------  Main (Driver) ------
int main(void)
{


  ItemType Item1 = {'A', 4.1};
  ItemType Item2 = {'B', 3.1};
  ItemType Item3 = {'C', 2.1};
  ItemType Item4 = {'D', 1.0};
  ItemType tmpItem;

  List dList;
  std::cout << " List created"       << std::endl;
  dList.InsertBefore(Item2);
  dList.InsertAfter(Item3);
  dList.MoveFirst();
  dList.InsertBefore(Item1);
  dList.MoveLast();
  dList.InsertAfter(Item4);




  std::cout << " List contains the following Items:"       << std::endl;
  dList.MoveFirst();

  for (int iloop = 1; iloop <= dList.Count(); iloop++)
  {
	  std::cout << "     Item " << iloop << " : " ;
	  tmpItem = dList.CurrentItem();		  
	  std::cout << " Key = " <<tmpItem.key 
	            << " Data = " <<tmpItem.data 
				<< std::endl;
	  dList.MoveNext();
  }

  char searchkey;
  std::cout << "Enter item to find:" ;
  std::cin >> searchkey;
  std::cout << std::endl;
  std::cout << "Key was " ;
  if (dList.Find(searchkey))
  {
	  tmpItem = dList.CurrentItem();
	  std::cout << "Found - Value = " << tmpItem.data << std::endl;
  }
  else
	  std::cout << "Not Found " << std::endl;

  return 0;
}

