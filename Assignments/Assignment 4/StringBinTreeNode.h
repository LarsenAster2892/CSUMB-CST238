//********************************************************
// File Name   : StringBinTreeNode.h   
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Header file for StringBinTreeNode Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "BinTreeNode.h"
#include <string>
using std::string;


#ifndef STRINGBINTREENODE_h
#define STRINGBINTREENODE_h
//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A DataContainer Class 
//
// Base Classes: BinTreeNode
//
//===================================================================

//
// --- CONSTANTS -----
// 
//const int DEFAULT_SIZE = 10;		// The number of elements in the arrary

class StringTreeNode : public BinTreeNode
{
	private:
	//
	// -- data members -----
	//

	string mString;
	

	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		StringTreeNode(string str = "/0");


		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~StringTreeNode();
		
		//
		// ============= COPY CONSTRUCTOR =====================
		//
		//DataSlot(/* IN    */ DataSlot & copyItem); 
			//-------------------------------------------------
			// Pre : copyItem is Assigned
			// Post: (*this) is assigned values of copyItem
			//-------------------------------------------------

		//
		// ============= ACCESSORS =====================
		//
		string GetString(void) const ;
			//-------------------------------------------------
			// Pre : none
			// Post: string is returned
			//-------------------------------------------------
		
		//
		//========= OPERATOR FUNCTIONS ==================
		//
		bool operator<  (/* IN    */  BinTreeNode* pNode);
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is greater than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator>  (/* IN    */  BinTreeNode* pNode);
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is less than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		bool operator== (/* IN    */  BinTreeNode * pNode);
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is equal to (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------


		//
		//========= STREAM FUNCTIONS ==================
		//
		// ---- OUT STREAM ----
	    friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
										 /* IN    */ const StringTreeNode * stn);
			//----------------------------------------------------
			// Pre : os is valid iostream & ds is valid DataSlot
			// Post: iostream os contains outputted DataSlot
			//-------------------------------------------------

};

	std::ostream & operator<<(std::ostream &os, const StringTreeNode * stn);


#endif