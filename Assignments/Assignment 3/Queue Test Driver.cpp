//********************************************************
// File Name   : Queue Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Used to test Queue Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "QUEUE.H"
// ------ Functions -------


// ------  Main (Driver) ------
int main(void)
{

	
  ItemType Item1 = {'A', 4.1};
  ItemType Item2 = {'B', 3.1};
  ItemType Item3 = {'C', 2.1};
  ItemType Item4 = {'D', 1.0};
  ItemType tmpItem;

  Queue dQueue;
  std::cout << " Queue created"       << std::endl;
  std::cout << " Queue is "  << (dQueue.IsEmpty() ? "" : "Not ") <<  "Empty"  << std::endl;

  std::cout << std::endl;
  tmpItem = dQueue.Front();
  std::cout << " Key = " <<tmpItem.key 
            << " Data = " <<tmpItem.data 
			<< std::endl;

  std::cout << " Adding Items to Queue "       << std::endl;

  dQueue.Enqueue(Item1);
  dQueue.Enqueue(Item2);
  dQueue.Enqueue(Item3);
  dQueue.Enqueue(Item4);
 
  std::cout << " Queue is "  << (dQueue.IsEmpty() ? "" : "Not ") <<  "Empty"  << std::endl;

   std::cout << " Front of the Queue is : " ;      
	  tmpItem = dQueue.Front();
	  std::cout << " Key = " <<tmpItem.key 
	            << " Data = " <<tmpItem.data 
				<< std::endl;
	  
  
  std::cout << " Queue contains the following Items:"       << std::endl;
  
  int iloop = 0;

  while (!dQueue.IsEmpty())
  {
	  iloop++;
	  std::cout << "     Item " << iloop << " : " ;
	  tmpItem = dQueue.Dequeue();
	  std::cout << " Key = " <<tmpItem.key 
	            << " Data = " <<tmpItem.data 
				<< std::endl;

  }

    return 0;
}

