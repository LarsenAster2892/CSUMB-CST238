//***********************************************************************
// File Name   : StringBinaryTree.cpp      
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Class member functions for StringBinaryTree Class 
// ---------------------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// *********************************************************************
//
// --- INCLUDES -----
// 
#include "stdafx.h"
#include "stringbinarytree.h"
//
// ================= Constructors ==========================
//

StringBinaryTree::StringBinaryTree(void)
{
}

//
// ================= Destructor ==========================
//

StringBinaryTree::~StringBinaryTree(void)
{
	Clear();
}

//
// ================= Member Methods ==========================
//
void StringBinaryTree::Add(string str)
{
	Insert( new StringTreeNode(str) );
}

bool StringBinaryTree::Delete(string str)
{
  StringTreeNode searchNode(str); 

  return RemoveNode(&searchNode);
}

void StringBinaryTree::DeleteNode(/* IN    */  BinTreeNode* pNode)
	//-------------------------------------------------
	// Pre : pNode is assigned and is of type pointer 
	//       to Tree Node
	// Post: Tree/SubTree node is deleted 
	//-------------------------------------------------
{
	delete (StringTreeNode*)pNode;
}


StringTreeNode* StringBinaryTree::FindByString(string str)
{
  StringTreeNode searchNode(str); 

  StringTreeNode* pRes = (StringTreeNode*) Find(&searchNode);
  return pRes;
}


void StringBinaryTree::PrintNode(/* IN    */  BinTreeNode* pNode)
	//-------------------------------------------------
	// Pre : pNode is assigned and is of type pointer 
	//       to Tree Node
	// Post: Tree/SubTree node is printed 
	//-------------------------------------------------
{
	
	cout << (StringTreeNode *) pNode  << endl;
}


int StringBinaryTree::InsertRecursively(/* IN    */  BinTreeNode* pbParent,
	            		                /* IN    */  BinTreeNode* pbNewNode)
	//-------------------------------------------------
	// Pre : pParent and PNewNode are assigned.
	//       pParent and PNewNode are of type pointer 
	//       to Tree Node
	// Post: if a node with the data in pNode is NOT found in tree         
	//			a tree will contain tree plus node
	//       else
	//          return
	//  (INORDER TRAVERSAL - LEFT,  PARENT, RIGHT)
	//-------------------------------------------------
{
	int returnValue = 1;
    StringTreeNode * pParent = (StringTreeNode *) pbParent;
	StringTreeNode * pNewNode = (StringTreeNode *) pbNewNode;
		
	if (pNewNode->GetString() < pParent->GetString())
	{
		if (pParent->GetLeftChild()== NULL)
		{
			// No left child? Okie then, mNewNode is the new left child 
			pParent->SetLeftChild(pNewNode);
			pNewNode->SetParent(pParent);
		}
		else
		{
			returnValue += InsertRecursively(pParent->GetLeftChild(),pNewNode);
		}
	}
	else if (pNewNode->GetString() > pParent->GetString())
	{
		if (pParent->GetRightChild()==NULL)
		{
			// No right child? Okie then, mNewNode is the new right child 
			pParent->SetRightChild(pNewNode);
			pNewNode->SetParent(pParent);
		}
		else
		{
			returnValue += InsertRecursively(pParent->GetRightChild(),pNewNode);
		}
	}

	else
	{
		// Duplicate!!! Already in tree
		returnValue = 0;
	}

	return (returnValue);


}


BinTreeNode* StringBinaryTree::FindRecursively(/* IN    */  BinTreeNode* pbNode,
										       /* IN    */  BinTreeNode* pbSearchNode)
	//-------------------------------------------------
	// Pre : pNode is assigned.
	// Post: if a node with the data in pNode is  found in tree         
	//			returns pointer to that node
	//       else
	//          returns null
	//  (PREORDER TRAVERSAL - LEFT, RIGHT , PARENT)
	//-------------------------------------------------
{
	StringTreeNode * pNode = (StringTreeNode *) pbNode;
    StringTreeNode * pSearchNode = (StringTreeNode *) pbSearchNode;
	
	// Reached a dead end, node couldn't be found.
   if (!pNode)
	  return NULL;

  // Found the node we were looking for, return it.
  if (pNode->GetString() == pSearchNode->GetString())
	  return pNode;

  // node > mpSearchNode, look if it is by the left 
  if (pNode->GetString() > pSearchNode->GetString())
	  return FindRecursively(pNode->GetLeftChild(), pSearchNode);
  
  // node < mpSearchNode, look if it is by the right
  return FindRecursively(pNode->GetRightChild(), pSearchNode);

}

bool IsEqual(BinTreeNode* pNode1, BinTreeNode* pNode2)
{
   StringTreeNode * pNodeA = (StringTreeNode *) pNode1;
   StringTreeNode * pNodeB = (StringTreeNode *) pNode2;
   return( pNodeA->GetString() == pNodeB->GetString());
}

bool IsLessThan(BinTreeNode* pNode1, BinTreeNode* pNode2)
{
   StringTreeNode * pNodeA = (StringTreeNode *) pNode1;
   StringTreeNode * pNodeB = (StringTreeNode *) pNode2;
   return( pNodeA->GetString() < pNodeB->GetString());

}

bool IsGreaterThan(BinTreeNode* pNode1, BinTreeNode* pNode2)
{
   StringTreeNode * pNodeA = (StringTreeNode *) pNode1;
   StringTreeNode * pNodeB = (StringTreeNode *) pNode2;
   return( pNodeA->GetString() > pNodeB->GetString());

}
