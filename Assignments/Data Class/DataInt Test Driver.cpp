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
#include "DataInt.H"
#include "DataContainerInt.h"
#include "DataSlot.h"
#include "DataContainerSlot.h"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// ------ Functions -------

// ------  Main (Driver) ------
int main(void)
{
    //
	//  Test with Primary Type
	//
	DataInt di1,
			di2,
			tmp;

	
	DataContainerInt dc;

	di1.Set(30);
	//di2.Set(10);

	dc.AddItem(di1);

	di1.Set(30);

	dc.AddItem(di1);

	cout << "compare " 
		 << dc.GetItem(0);
	
	if (dc.GetItem(0) < dc.GetItem(1))
		cout << " < ";
	else
	if (dc.GetItem(0) > dc.GetItem(1))
		cout << " > ";
	else
		cout << " == ";
	
	cout << dc.GetItem(1)
		 << " ";

	cout << endl;

    //
	//  Test with UserDefined Type
	//
		DataSlot ds1,
	   		     ds2;
				
        Slot	tmpSlot;
	    DataContainerSlot dcs;

	tmpSlot.key("Key 1     ");
	tmpSlot.data("Data 1              ");


	ds1.Set(tmpSlot);

	dcs.AddItem(ds1);

	DataSlot ds3 = ds1;

	tmpSlot.key("Key 2     ");
	tmpSlot.data("Data 2              ");


	ds1.Set(tmpSlot);

	dcs.AddItem(ds1);

	

	cout << "compare " 
		 << dcs.GetItem(0).Get()
		 << " to "
		 << dcs.GetItem(1).Get()
		 << " ";
	
	if (dcs.GetItem(0) < dcs.GetItem(1))
	{
		cout << " < ";
	}
	else
	if (dcs.GetItem(0) > dcs.GetItem(1))
	{
		cout << " > ";
	}
	else
	{
		cout << " == ";
	}
	cout << endl;
	
	cout << "DataSlot 1 = " << dcs.GetItem(0) << endl;
	cout << "DataSlot 3 = " << ds3 << endl;

    return 0;
}

