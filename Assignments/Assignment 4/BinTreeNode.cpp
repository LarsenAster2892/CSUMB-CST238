//********************************************************
// File Name   : BinTreeNode.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Class member functions for Binary Tree Node Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"

#include "BINTREENODE.H"

//
// ================= Constructors ==========================
//

//
// initailize Tree Node
//

BinTreeNode::BinTreeNode()
//-------------------------------------------------
// Pre : none
// Post: TreeNode LeftChild, RightChild and Parent
//       are initialized to NULL
//-------------------------------------------------
{
   mLeftChild = NULL;
   mRightChild = NULL;
   mParent = NULL;
}


//
// ================= Destructor ==========================
//
BinTreeNode::~BinTreeNode()
//-------------------------------------------------
// Pre : none
// Post: Class is destructed
//-------------------------------------------------
{
}

//
// ================= Accessors ==========================
//

//
// Get Left Child
//
BinTreeNode* BinTreeNode::GetLeftChild(void) const
//-------------------------------------------------
// Pre : none
// Post: Pointer to Left Child is returned
//-------------------------------------------------
{
	return (mLeftChild);
}


//
// Get Right Child
//
BinTreeNode* BinTreeNode::GetRightChild(void) const
//-------------------------------------------------
// Pre : none
// Post: Pointer to Left Child is returned
//-------------------------------------------------
{
	return (mRightChild);
}



//
// Get Parent
//
BinTreeNode* BinTreeNode::GetParent(void) const
//-------------------------------------------------
// Pre : none
// Post: Pointer to Left Child is returned
//-------------------------------------------------
{
	return (mParent);
}



//
// ================= Mutators ==========================
//

//
// Set Left Child
//
void BinTreeNode::SetLeftChild(/* IN    */ BinTreeNode* pNode)
//-----------------------------------------------------
// Pre : none
// Post: Left Child Pointer is set to point to new Item
//-----------------------------------------------------
{
	mLeftChild=pNode;
}

//
// Set Right Child
//
void BinTreeNode::SetRightChild(/* IN    */ BinTreeNode* pNode)
//-------------------------------------------------------
// Pre : none
// Post: Right Child Pointer is set to point to new Item
//-------------------------------------------------------
{
	mRightChild=pNode;
}

//
// Set Parent
//
void BinTreeNode::SetParent(/* IN    */ BinTreeNode* pNode)
//-------------------------------------------------
// Pre : none
// Post: Parent Pointer is set to point to new Item
//-------------------------------------------------
{
	mParent=pNode;
}



//
// ================= Member Methods ==========================
//

//

//
// ================= Operators ==========================
//

