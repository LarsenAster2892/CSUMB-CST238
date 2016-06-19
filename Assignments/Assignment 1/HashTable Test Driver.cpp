//********************************************************
// File Name   : HashTable Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : September 10, 2003 (5:30 PM)
// Description : Used to test HashTable Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "HASHTABLE.H"

//
// --- CONSTANTS -----
// 
const char * pFileLocationDataFile = "E:\\DATAFILES\\DATAIN";
const char * pFileLocationHashTable = "E:\\DATAFILES\\HashTable";
const char * pFileLocationSearchFile = "E:\\DATAFILES\\SEARCH";
enum  restore_report_type { BEFORE_RESTORE  , AFTER_RESTORE  };

//
// --- USING STATEMENTS -----
// 
using std::string;

// ------ Functions -------
void LoadHashTable     (/* IN    */ const char *pFileLocation, 
						/* OUT   */ Hashtable & HT);

void PrintHashTable    (/* IN    */ restore_report_type report_type, 
						/* IN    */ const Hashtable & HT);

void WriteHashTable    (/* IN    */ const char *pFileLocation, 
						/* IN    */ const Hashtable & HT);

void RestoreHashTable  (/* IN    */ const char *pFileLocation, 
						/* OUT   */ Hashtable & HT);

void CreateSearchReport(/* IN    */ const char *pFileLocation, 
						/* IN    */ Hashtable & HT);

void CreateLengthReport  (/* IN    */ const Hashtable & HT);

// ------  Main (Driver) ------
int main(void)
{
  Hashtable  HT;
  HT.Clear();

  LoadHashTable(pFileLocationDataFile,HT);
  
  PrintHashTable(BEFORE_RESTORE,HT);
  
  WriteHashTable(pFileLocationHashTable,HT);
  
  HT.Clear();
  
  RestoreHashTable(pFileLocationHashTable,HT);

  PrintHashTable(AFTER_RESTORE,HT);

  CreateSearchReport(pFileLocationSearchFile,HT);

  CreateLengthReport(HT);

  return 0;
}



void LoadHashTable     (/* IN    */ const char *pFileLocation, 
						/* OUT   */ Hashtable & HT)
//-------------------------------------------------
// Pre : pFileLocation is assigned a valid file name
// Post: HT is loaded
//-------------------------------------------------
{
	STR10 key;
	STR20 data;

	//
	// ---- FILE OBJECT 
    //
	std::ifstream fin;

	fin.open(pFileLocation);

	while (fin.get(key,11))
	{
		
		fin.get(data,21);

		key[10]='\0';
		data[20]='\0';

		HT.Insert(key,data);
		fin.ignore();
	}
	fin.close();
	return;
}


void PrintHashTable    (/* IN    */ restore_report_type report_type, 
						/* IN    */ const Hashtable & HT)
//-------------------------------------------------
// Pre : restore report type is assigned
// Post: ht (hashtable) is printed
//-------------------------------------------------

{
	std::ios_base::fmtflags io_flags = std::cout.flags();
	int io_precision = std::cout.precision();
	char io_fill = std::cout.fill();
	
	string restore_title = ((report_type == BEFORE_RESTORE ? "BEFORE" : "AFTER"));
	string report_type_line = restore_title + " Restoration";


	std::cout  << std::right
		       << std::setw(40)
		       << "Hash Table"
		       << std::endl
			   << std::setw(45)
			   << "Verification Report"
		       << std::endl
			   << std::setw(44)
			   << report_type_line
		       << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

    std::cout << HT
	          << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	
	//
	// --- restore io stream settings ---
	std::cout.flags(io_flags);
	std::cout.precision(io_precision);
	std::cout.fill(io_fill);

	return;
}

void WriteHashTable    (/* IN    */ const char *pFileLocation, 
						/* IN    */ const Hashtable & HT)
//-------------------------------------------------
// Pre : pFileLocation is assigned a valid file name
// Post: HT is written to pFileLocation
//-------------------------------------------------
{
	//
	// ---- FILE OBJECT 
    //
	std::ofstream fin;

	fin.open(pFileLocation,std::ios_base::binary);

	fin.write((char *) &HT, sizeof HT);

	return;
}


void RestoreHashTable  (/* IN    */ const char *pFileLocation, 
						/* OUT   */ Hashtable & HT)
//-------------------------------------------------
// Pre : pFileLocation is assigned a valid file name
// Post: HT is restored from pFileLocation
//-------------------------------------------------
{
	//
	// ---- FILE OBJECT 
    //
	std::ifstream fin;

	fin.open(pFileLocation,std::ios_base::binary);

	fin.read((char *) &HT, sizeof HT);

	return;
}

void CreateSearchReport(/* IN    */ const char *pFileLocation, 
						/* INOUT */ Hashtable & HT)
//-------------------------------------------------
// Pre : pFileLocation is assigned a valid file name
// Post: search report is generated
//-------------------------------------------------
{
	std::ios_base::fmtflags io_flags = std::cout.flags();
	int io_precision = std::cout.precision();
	char io_fill = std::cout.fill();


	std::cout  << std::right
			   << std::setw(43)
			   << "Search and Retrieval"
		       << std::endl
			   << std::setw(39)
			   << "Transactions"
		       << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout  << std::left
		       << std::setw(10)
		       << "Search Key"
		       << std::setw(5)
			   << " "
			   << std::setw(12)
			   << "Bucket/Slot"
		       << std::setw(5)
			   << " "
			   << std::setw(44)
			   << std::left
			   << "--- Record Data ----"
		       << std::endl;



	STR10 key;
	STR20 data;
	int bucket_number;
	int slot_number;

	//
	// ---- FILE OBJECT 
    //
	std::ifstream fin;

	fin.open(pFileLocation);

	while (fin.getline(key,11))
	{
		//fin.ignore();
		std::cout << std::setw(10)
			      << std::left
			      << key
				  << std::setw(7)
			      << " ";

		if (HT.GetData(key,bucket_number,slot_number,data))
		{
			std::cout << std::setw(2)
				      << std::right
					  << bucket_number
					  << std::setw(1)
					  << "/"
					  << slot_number
					  << std::setw(11)
					  << " "
					  << std::setw(20)
					  << data
					  << std::endl;
		}
		else
		{
			std::cout  << std::setw(15)
			           << " "
				       << std::setw(20)
					   << "Record not found"
					   << std::endl;

		}

	}
	fin.close();
	std::cout << std::endl;
	std::cout << std::endl;

	
	//
	// --- restore io stream settings ---
	std::cout.flags(io_flags);
	std::cout.precision(io_precision);
	std::cout.fill(io_fill);

	return;
}

void CreateLengthReport  (/* IN    */ const Hashtable & HT)
//-------------------------------------------------
// Pre : pFileLocation is assigned a valid file name
// Post: Length report is generated
//-------------------------------------------------
{
	std::ios_base::fmtflags io_flags = std::cout.flags();
	int io_precision = std::cout.precision();
	char io_fill = std::cout.fill();



	std::cout  << std::right
		       << std::setw(40)
		       << "Hash Table"
		       << std::endl
			   << std::setw(45)
			   << "Total Length Report"
		       << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;


	HT.Generate_Length_Report(std::cout);

	
	//
	// --- restore io stream settings ---
	std::cout.flags(io_flags);
	std::cout.precision(io_precision);
	std::cout.fill(io_fill);

	return;
}
