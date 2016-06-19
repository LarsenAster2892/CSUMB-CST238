//********************************************************
// File Name   : Bucket Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Used to test Bucket Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "BUCKET.H"
using std::string;

// ------ Functions -------


// ------  Main (Driver) ------
int main(void)
{
  Bucket  btest1;

  btest1.Insert("KEY1","DATA1");
      if (!(btest1.Insert("KEY2","DATA2"))) 
	{
		std::cout << " Cannot insert 2ND item" << std::endl;
	}
	else
	{
		std::cout << "Inserted" << std::endl;
	}
/*     if (!(btest1.Insert("KEY3","DATA3"))) 
	{
		std::cout << " Cannot insert 3RD item" << std::endl;
	}
	else
	{
		std::cout << "Inserted" << std::endl;
	}





     if (!(btest1.Insert("KEY4","DATA4"))) 
	{
		std::cout << " Cannot insert 4th item" << std::endl;
	}
	else
	{
		std::cout << "Inserted" << std::endl;
	}
 */ std::cout << " Bucket is as follows:"       << std::endl;
  std::cout << std::endl;

  std::cout 
     << btest1
	 << std::endl;


  return 0;
}

