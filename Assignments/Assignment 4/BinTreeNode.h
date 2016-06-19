//********************************************************
// File Name   : BinTreeNode.h       
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Header file for Binary Tree Node Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <iostream>
#include <iomanip>

#ifndef BINTREENODE_h
#define BINTREENODE_h


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class used to describe a node 
//                          within the Binary Tree
//
//
//===================================================================

class  BinTreeNode
{
	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
	    BinTreeNode* mLeftChild;		// Pointer to Left Child
	    BinTreeNode* mRightChild;		// Pointer to Right Child

		BinTreeNode* mParent;			// Pointer to Parent (Null for Root)
		// This just makes the  deletion a bit easier, but
		// technically you could live without it since it is a bit redundant.
		
	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:
		

	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		BinTreeNode();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~BinTreeNode();

	
			 
		//
		// ============= ACCESSORS =====================
		//
		BinTreeNode* GetLeftChild(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: Pointer to Left Child is returned
			//-------------------------------------------------

		BinTreeNode* GetRightChild(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: Pointer to Right Child is returned
			//-------------------------------------------------

		BinTreeNode* GetParent(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: Pointer to Parent Child is returned
			//-------------------------------------------------


		//
		// ============= MUTATORS =====================
		//
		void SetLeftChild(/* IN    */ BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : none
			// Post: Left Child Pointer is set to point to new Item
			//-------------------------------------------------

		void SetRightChild(/* IN    */ BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : none
			// Post: Right Child Pointer is set to point to new Item
			//-------------------------------------------------

		void SetParent(/* IN    */ BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : none
			// Post: Parent Pointer is set to point to new Item
			//-------------------------------------------------


		//
		// ============= MEMBER METHODS =====================
		//

		//
		//========= OPERATOR FUNCTIONS ==================
		//
		virtual bool operator<  (/* IN    */  BinTreeNode* pNode) = 0;
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is greater than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		virtual bool operator>  (/* IN    */  BinTreeNode* pNode) = 0;
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is less than (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------

		virtual bool operator== (/* IN    */  BinTreeNode* pNode) = 0;
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if pNode key is equal to (this) key	         
			//			returns true 
			//       else
		    //          returns false
			//----------------------------------------------------------


};

#endif