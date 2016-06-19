//***********************************************************************
// File Name   : StringBinTreeNode.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Class member functions for StringBinTreeNode Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "stdafx.h"
#include "stringbintreenode.h"

//
// ================= Constructors ==========================
//
StringTreeNode::StringTreeNode(string str)
	//-------------------------------------------------
	// Pre : <none>
	// Post: Class is initialized
	//-------------------------------------------------
{
	mString = str;
}


//
// ================= Destructor ==========================
//
StringTreeNode::~StringTreeNode(void)
//-------------------------------------------------
// Pre : none
// Post: Class is destructed
//-------------------------------------------------
{
}


//
// ================= Member Methods ==========================
//
// ============= ACCESSORS =====================
//
//
//
//  -----Get data -----
//
string StringTreeNode::GetString(void) const
//-------------------------------------------------
// Pre : none
// Post: key is returned
//-------------------------------------------------
{
	return (mString);
}



//
// ============= MUTATORS =====================
//
//


//
// ================= Operators ==========================
//


bool StringTreeNode::operator <  (/* IN    */  BinTreeNode* pNode) 
//-----------------------------------------------------------
// Pre : pNode is assigned and is of type BinTreeNode
// Post: if pNode key is greater than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	// Force base class item to drived class 
	// (upcasting) User beware 
	StringTreeNode * pSBTN = (StringTreeNode *) pNode; 
											         

	return (mString < pSBTN->GetString() );
}

bool StringTreeNode::operator >  (/* IN    */  BinTreeNode* pNode) 
//-----------------------------------------------------------
// Pre : pNode is assigned and is of type BinTreeNode
// Post: if pNode key is less than (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------
{
	// Force base class item to drived class 
	// (upcasting) User beware 
	StringTreeNode * pSBTN = (StringTreeNode *) pNode; 


	return (mString > pSBTN->GetString());
}


bool StringTreeNode::operator ==  (/* IN    */  BinTreeNode* pNode) 
//-----------------------------------------------------------
// Pre : pNode is assigned and is of type BinTreeNode
// Post: if pNode key is equal to (this) key	         
//			returns true 
//       else
//          returns false
//----------------------------------------------------------

{
	// Force base class item to drived class 
	// (upcasting) User beware 
	StringTreeNode * pSBTN = (StringTreeNode *) pNode; 
	
	return (mString == pSBTN->GetString());
}





//
// --- STREAM OVERLOAD OPERATORS ---
// Outputs slot to iostream
std::ostream & operator<<(/* INOUT */ std::ostream &os,
						  /* IN    */ const StringTreeNode * stn)
//----------------------------------------------------
// Pre : os is valid iostream & s is valid slot
// Post: iostream os contains outputted slot
//-------------------------------------------------
{
	//
	//-- save io stream settings ---
	std::ios_base::fmtflags io_flags = os.flags();
	int io_precision = os.precision();
	char io_fill = os.fill();

	
	os << stn->GetString() ;    // Cast as a Slot as use Slot output stream function

	//
	// --- restore io stream settings ---
	os.flags(io_flags);
	os.precision(io_precision);
	os.fill(io_fill);

	return os;
}
