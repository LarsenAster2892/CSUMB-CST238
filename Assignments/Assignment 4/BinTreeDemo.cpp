//********************************************************
// File Name   : Binary Tree Test Driver.cpp       
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Used to test Binary Tree Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
//
//  --- Windows stuff for Later Graphic Printing
//
#include "stdafx.h"

CWinApp theApp;

using namespace std;


#include "StringBinaryTree.h"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::getline;


//int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// Standard autogenereated stuff...
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
	    char filename[255] = "C:\\Assignment4_Data.txt" ;
		
		StringBinaryTree tree;

		string wordphrase;
		ifstream fin;

		fin.open(filename);

		cout << "Processing Input File:" << endl;
		cout << "---------------------" << endl;
	

		while(!fin.eof())
		{
			getline(fin,wordphrase);
			cout << wordphrase << endl;
		    tree.Add(wordphrase);

		}
		fin.close();
		cout << "---------------------" << endl;
		cout << "Press enter...";cin.get();

		cout << endl;
		cout << endl;

		//
		// ---- Print in Ascending
		//

		cout << "Traverse(Ascending):" << endl;;
		cout << "---------------------" << endl;;

		tree.PrintTree(BinaryTree::Ascending);		

		cout << "---------------------" << endl;;
		cout << "Press enter...";cin.get();
		cout << endl;
		cout << endl;

		//
		// ---- Print in Desceding
		//
		cout << "Traverse(Descending):" << endl;
		cout << "---------------------" << endl;

		tree.PrintTree(BinaryTree::Descending);		

		cout << "---------------------" << endl;
		cout << "Press enter...";cin.get();
		
		cout << endl;
		cout << endl;
		cout << "Deleting items:" << endl;
		cout << "---------------------" << endl;;

		tree.Delete("Isolation");
		tree.Delete("Normalization");
		tree.Delete("Distributed Processing");
		cout << "Items Deleted" << endl;
		cout << "---------------------" << endl;;
		cout << "Press enter...";cin.get();
		
		cout << endl;
		cout << endl;
	

		//
		// ---- Print in Ascending
		//

		cout << "Traverse(Ascending):" << endl;;
		cout << "---------------------" << endl;;

		tree.PrintTree(BinaryTree::Ascending);		

		cout << "---------------------" << endl;;
		cout << "Press enter...";cin.get();
		cout << endl;
		cout << endl;

		//
		// ---- Print in Desceding
		//
		cout << "Traverse(Descending):" << endl;
		cout << "---------------------" << endl;

		tree.PrintTree(BinaryTree::Descending);		

		cout << "---------------------" << endl;
		cout << "Press enter...";cin.get();
		
		cout << endl;
		cout << endl;



		cout << "Press enter to exit...";cin.get();

	}

	return nRetCode;
}


