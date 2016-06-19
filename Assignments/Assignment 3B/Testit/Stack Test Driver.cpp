//********************************************************
// File Name   : Stack Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : September 22, 2003 (5:30 PM)
// Description : Used to test Slack Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "STACK.H"
// ------ Functions -------

using std::string;

// ------  Main (Driver) ------
int main(void)
{

	
 //ItemType Item1 = {string("A"), 4.1};
  ItemType Item1;
  Item1.key = "A";
  Item1.data = 4.1;
  ItemType Item2;
  Item2.key = "B";
  Item2.data = 3.1;
  ItemType Item3;
  Item3.key = "C";
  Item3.data = 2.1;
  ItemType Item4;
  Item4.key = "SIN";
  Item4.data = 1.0;
  //ItemType Item2 = {"B", 3.1};
  //ItemType Item3 = {"C", 2.1};
  //ItemType Item4 = {"SIN", 1.0};
  ItemType tmpItem;

  Stack dStack;
  std::cout << " Stack created"       << std::endl;
  std::cout << " Stack is "  << (dStack.IsEmpty() ? "" : "Not ") <<  "Empty"  << std::endl;

  std::cout << " Adding Items to Stack "       << std::endl;

  dStack.Push(Item1);
  dStack.Push(Item2);
  dStack.Push(Item3);
  dStack.Push(Item4);
 
  std::cout << " Stack is "  << (dStack.IsEmpty() ? "" : "Not ") <<  "Empty"  << std::endl;

   std::cout << " Top of the Stack is : " ;      
	  tmpItem = dStack.Top();
	  std::cout << " Key = " <<tmpItem.key 
	            << " Data = " <<tmpItem.data 
				<< std::endl;
	  
  
  std::cout << " Stack contains the following Items:"       << std::endl;
  
  int iloop = 0;

  while (!dStack.IsEmpty())
  {
	  iloop++;
	  std::cout << "     Item " << iloop << " : " ;
	  tmpItem = dStack.Pop();
	  std::cout << " Key = " <<tmpItem.key 
	            << " Data = " <<tmpItem.data 
				<< std::endl;

  }

    return 0;
}

