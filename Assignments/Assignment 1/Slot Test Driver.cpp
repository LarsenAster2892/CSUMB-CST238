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
#include "SLOT.H"
// ------ Functions -------


// ------  Main (Driver) ------
int main(void)
{


  Slot test1;
  Slot test2("KEY2","DATA2");
  Slot test3("K");

  std::cout << " Slots  are as follows:"       << std::endl;
  std::cout << std::endl;

  std::cout 
     << test1
	 << std::endl;

  std::cout 
     << test2
	 << std::endl;

  std::cout 
     << test3
	 << std::endl;


  return 0;
}

