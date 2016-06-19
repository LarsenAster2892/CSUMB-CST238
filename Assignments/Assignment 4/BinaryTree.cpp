//********************************************************
// File Name   : BinTree.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Class member functions for Binary Tree Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"
using std::cout;
using std::endl;

#include "BinaryTree.H"

//
// ================= Constructors ==========================
//

//
// initailize Tree Node
//

BinaryTree::BinaryTree()
//-------------------------------------------------
// Pre : none
// Post: TreeNode LeftChild, RightChild and Parent
//       are initialized to NULL
//-------------------------------------------------
{
	mRoot = NULL;
	mNodeCount = 0;
	mTreeHeight = 0;
}


//
// ================= Destructor ==========================
//
BinaryTree::~BinaryTree()
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
// Get Number of nodes in the tree.
//
int BinaryTree::GetNodeCount(void) const 
//-------------------------------------------------
// Pre : none
// Post: current value of number of nodes is returned
//-------------------------------------------------
{
	return (mNodeCount);
}


//
// Get the height of the tree
//
int BinaryTree::GetTreeHeight(void) const 
//-------------------------------------------------
// Pre : none
// Post: current value of Tree height is returned
//-------------------------------------------------
{
	return (mTreeHeight);
}




//
// ================= Mutators ==========================
//



//
// ================= Member Methods ==========================
//
void BinaryTree::Clear(void)
//-------------------------------------------------
// Pre : none
// Post: count and height are reset
//-------------------------------------------------
{
		DeleteAllRecursively(mRoot);
		mRoot = NULL;
		mNodeCount=0;
		mTreeHeight=0;
}

void BinaryTree::DeleteAllRecursively(/* IN    */  BinTreeNode* pNode)
	//-------------------------------------------------
	// Pre : pParent and PNewNode are assigned.
	//       pParent and PNewNode are of type pointer 
	//       to Tree Node
	// Post: if a node with the data in pNode is NOT found in tree         
	//			a tree will contain tree plus node
	//       else
	//          return
	//  (PREORDER TRAVERSAL - LEFT, RIGHT , PARENT)
	//-------------------------------------------------
{
	if (!pNode)
		return;

	DeleteAllRecursively(pNode->GetLeftChild());
	DeleteAllRecursively(pNode->GetRightChild());
	DeleteNode(pNode);

}



BinTreeNode* BinaryTree::Find(/* IN    */BinTreeNode* pSearchNode)
	//-----------------------------------------------------------
	// Pre : pSearchNode is assigned and is of type BinTreeNode
	// Post: if a node with the data in pSearchNode is found in tree
	//			returns pointer to node
	//       else
	//          returns NULL
	//-----------------------------------------------------------
{
	mpSearchNode = pSearchNode;
	return (FindRecursively(mRoot, pSearchNode));

}


void BinaryTree::Insert(/* IN    */BinTreeNode* pNode)
	//-----------------------------------------------------------
	// Pre : pNode is assigned and is of type BinTreeNode
	// Post: if a node with the data in pNode is NOT found in tree         
	//			a tree will contain tree plus node
	//       else
	//          return
	//----------------------------------------------------------
{
  if (mRoot == NULL)
  {
	  mRoot = pNode;
	  mNodeCount = 1;
	  mTreeHeight = 1;
	  mRoot->SetParent(NULL);
  }
  else
  {
	  int lHeightTmp = 1;

      lHeightTmp += InsertRecursively(mRoot, pNode);
	  mNodeCount++;

	  if (lHeightTmp > mTreeHeight)
		  mTreeHeight = lHeightTmp;
  }

}



void BinaryTree::PrintTree(/* IN    */PrintOrderType PrintOrder)
	//-----------------------------------------------------------
	// Pre : PrintOrder is assigned 
	// Post: Tree is printed in the order specified by PrintOrder         
	//----------------------------------------------------------
{
	switch(PrintOrder)
	{
		case (Ascending):
			{
			 PrintRecursivelyAscending(mRoot);
			 break;
			}

		case (Descending):
			{
			 PrintRecursivelyDescending(mRoot);
			 break;
			}

		case (Graphic):
		{
			PrintRecursivelyGraphic(mRoot,0);
		}
	}
}

void BinaryTree::PrintRecursivelyAscending(/* IN    */  BinTreeNode* pNode)
	//-------------------------------------------------
	// Pre : pNode is assigned and is of type pointer 
	//       to Tree Node
	// Post: Tree/SubTree is printed in ascending order 
	//       by recursive calls
	//-------------------------------------------------
{
	if (!pNode)
		return;

	PrintRecursivelyAscending(pNode->GetLeftChild());
	PrintNode(pNode);
	PrintRecursivelyAscending(pNode->GetRightChild());

}



void BinaryTree::PrintRecursivelyDescending(/* IN    */  BinTreeNode* pNode)
	//-------------------------------------------------
	// Pre : pNode is assigned and is of type pointer 
	//       to Tree Node
	// Post: Tree/SubTree is printed in descending order 
	//       by recursive calls
	//-------------------------------------------------
{
	if (!pNode)
		return;

	PrintRecursivelyDescending(pNode->GetRightChild());
	PrintNode(pNode);
	PrintRecursivelyDescending(pNode->GetLeftChild());

}


void BinaryTree::PrintRecursivelyGraphic(/* IN    */  BinTreeNode* pNode,
										 /* IN    */ int Depth)
	//-------------------------------------------------
	// Pre : pNode is assigned and is of type pointer 
	//       to Tree Node.
	//       Depth is assigned is not < 0 and not 
	//       Greater than maximum tree depth
	// Post: Tree/SubTree is printed in reverse in-order
	//       by recursive calls
	//-------------------------------------------------
{
	if (pNode != NULL)
	{
		PrintRecursivelyGraphic(pNode->GetRightChild(), Depth+1);
		cout << std::setw(Depth*8) << "";
		PrintNode(pNode);
		PrintRecursivelyGraphic(pNode->GetLeftChild(), Depth+1);
	}
}

bool BinaryTree::RemoveNode(BinTreeNode* pSearchNode)
	//-----------------------------------------------------------
	// Pre : pSearchNode is assigned and is of type BinTreeNode
	// Post: if a node with the data in pSearchNode is found in tree         
	//			it is removed from the tree
	//       else
	//          return
	//----------------------------------------------------------
{
  BinTreeNode* pNode = Find(pSearchNode);
  if (!pNode)
	  return false;

 if (pNode->GetLeftChild() == NULL)
 {



  return (RemoveNodeRecursive(mRoot, pSearchNode));
  //int iCount = mNodeCount;
  //
  //BinTreeNode* pParent = pNode->GetParent();

  //// Found parent, now just disconnect it.
  //if (pParent)
  //{
	 // if (pParent->GetLeftChild() == pNode)
	 // {
		//  pParent->SetLeftChild(NULL);
	 // }
	 // else
	 // {
		//  pParent->SetRightChild(NULL);
	 // }
  //}
  //else
  //{
	 // // Parent is not found,  Then we're deleting the root node.
	 // // At this point (pNode == mRoot);
	 // mRoot = NULL;
  //}

  //// Disconnected, now we reconnect its children (if any)
  //// just by adding them as we add any other node. Their
  //// respective children will come along, since Insert doesn't
  //// tamper with the inserted node's children.
  //if (pNode->GetLeftChild())
	 // Insert(pNode->GetLeftChild());
  //
  //if (pNode->GetRightChild())
	 // Insert(pNode->GetRightChild());

  //mNodeCount = iCount-1;
  //DeleteNode(pNode);		
  //return true;


}


bool BinaryTree::RemoveNodeRecursive(BinTreeNode* pRoot, BinTreeNode* pSearchNode)
{
  
	if(IsLessThan(pSearchNode,pRoot)
		RemoveNodeRecursive(pRoot->GetLeftChild(),pSearchNode);
	
	if(IsGreaterThan(pSearchNode,pRoot)
		RemoveNodeRecursive(pRoot->GetRightChild(),pSearchNode);

	if (IsEqual(pSearchNode,pRoot,))
	{
		



	}
	else
		return false;
}


BinTreeNode* BinaryTree::FindMax(/* IN    */BinTreeNode* pSearchNode)
{
	
	mpSearchNode = pSearchNode;
	return (FindRecursively(mRoot, pSearchNode));

}