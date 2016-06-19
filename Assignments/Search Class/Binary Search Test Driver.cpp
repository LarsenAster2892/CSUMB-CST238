 
//********************************************************
// File Name   : DataInt Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : November 17, 2003 (5:30 PM)
// Description : Test Driver for the DataInt Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataInt.h"
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataContainerInt.h"
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataSlot.h"
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Data Class\DataContainerSlot.h"
#include "c:\Documents and Settings\cmitchell\My Documents\CISP430\CISP430 Briefcase\Assignments\Sort Class\QuickSortType.h"
#include "BinarySearchType.h"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;


//
// --- CONSTANTS -----
// 
const int MAX_DATACONTAINER_SIZE = 10;		// The number of elements for Data Container


// ------  Main (Driver) ------
int main(void)
{
	QuickSortType qs;

	cout << "Starting Primary Type Portion of Program ......." << endl;
    
	//=====================================================================
	//          TEST OF PRIMARY TYPE
	//=====================================================================

	cout << "     Defining DataInt Variables ...." << endl;

	DataInt          tmpDataInt;
	DataContainerInt dc(MAX_DATACONTAINER_SIZE);
    int              intRandNumber;

	cout << "     Seeding Random Number Generator ...." << endl;
	
	//
	// --- Seed Random Number Generator
	//
	srand( (unsigned)time( NULL ) );

	cout << "     Generating Random Numbers: ...." << endl;

	//
	// ====== Load data into data container
	//
	for (int iLoop = 0; iLoop < MAX_DATACONTAINER_SIZE ; iLoop++)
	{
		 intRandNumber = rand();			    // Generate Random Number
		 tmpDataInt.Set(intRandNumber);			// Set DataInt to generated Random Number
         dc.AddItem(tmpDataInt);				// Add to datacontainer 

	}
	
	//
	// ====== Output data in data container
	//
	dc.PrintItems();


	cout << endl;
	cout << "     Sorting Numbers (Descending) ...." << endl;
	cout << endl;

	qs.SetAscending();
	qs.Sort(dc);

	cout << "     Sorted Numbers: ...." << endl;


	//
	// ====== Output data in data container
	//
	dc.PrintItems();

	cout << endl;
	cout << endl;



	BinarySearchType bs;
	DataInt          searchValue;
	int				 returnIndex;

	cout << "Enter value to search for :";
	cin  >> searchValue;
	
	returnIndex = bs.Search(dc,searchValue);
	if (returnIndex == -1)
	{
		cout << "Value is not in DataContainer";
	}
	else
	{
		cout << "Value found in DataContainer at "
			<< returnIndex + 1
			<< endl;
	}
    
	cout << endl;
	cout << endl;

	
	
	//=====================================================================
	//          TEST OF USER DEFINED TYPE
	//=====================================================================

	qs.SetAscending();

	cout << "Starting User Defined Type Portion of Program ......." << endl;

	cout << "     Defining DataSlot Variables ...." << endl;

	DataSlot          tmpDataSlot;
	DataContainerSlot ds(MAX_DATACONTAINER_SIZE);

	
	cout << "     Creating Slots: ...." << endl;
	
	DataSlot tmpSlot;

	tmpSlot.key("Key A     ");
	tmpSlot.data("Data A              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 1     ");
	tmpSlot.data("Data 1              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 3     ");
	tmpSlot.data("Data 3              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 8     ");
	tmpSlot.data("Data 8              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 4     ");
	tmpSlot.data("Data 4              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 2     ");
	tmpSlot.data("Data 2              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 6     ");
	tmpSlot.data("Data 6              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 5     ");
	tmpSlot.data("Data 5              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 7     ");
	tmpSlot.data("Data 7              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	tmpSlot.key("Key 9     ");
	tmpSlot.data("Data 9              ");	
    ds.AddItem(tmpSlot);					// Add to datacontainer 

	//
	// ====== Output data in data container
	//
	ds.PrintItems();


	cout << endl;
	cout << "     Sorting Slots (Ascending) ...." << endl;
	cout << endl;

	qs.Sort(ds);

	cout << "     Sorted Slots: ...." << endl;

	//
	// ====== Output data in data container
	//
	ds.PrintItems();

	DataSlot		 searchValue1;
	DataSlot         searchValue2;
	
	searchValue1.key("Key 14    ");
	searchValue1.data("Data 4              ");	

	searchValue2.key("Key 4     ");
	searchValue2.data("Data 14             ");	

//
//  ---- Execute Binary Search for Item 1 (not found)
//
	cout << " Searching for value 1 " 
		 << searchValue1
		 << endl;

	returnIndex = bs.Search(ds,searchValue1);
	if (returnIndex == -1)
	{
		cout << "Value is not in DataContainer"
			 << endl;
	}
	else
	{
		cout << "Value found in DataContainer at "
			<< returnIndex + 1
			<< endl;
	}
    


//
//  ---- Execute Binary Search for Item 2 (found) 
//


	cout << " Searching for value 2 " 
		<< searchValue2
		<< endl;


	returnIndex = bs.Search(ds,searchValue2);
	if (returnIndex == -1)
	{
		cout << "Value is not in DataContainer"
			 << endl;
	}
	else
	{
		cout << "Value found in DataContainer at "
			<< returnIndex + 1
			<< endl;
	}
    
	cout << endl;

	cout << endl;
	cout << "END OF TEST DRIVER";
	cout << endl;

	return 0;
}

