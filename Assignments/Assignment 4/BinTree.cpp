//********************************************************
// File Name   : BinTree.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Class member functions for Binary Tree  Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include "stdafx.h"
#include "BinTree.h"
#include <iostream>
using std::cout;
using std::endl;


//
// ================= Constructors ==========================
//

//
// initailize Tree 
//

CBinTree::CBinTree()
//-------------------------------------------------
// Pre : none
// Post: Root, Count and Height are Initialized
//-------------------------------------------------
{
	mRoot = NULL;
	mComparisons = 0;
	mCount = 0;
	mHeight = 0;
}


//
// ================= Destructor ==========================
//

CBinTree::~CBinTree()
//-------------------------------------------------
// Pre : none
// Post: Class is destructed
//-------------------------------------------------
{
}

void CBinTree::Clear(void)
{
		Traverse(ParentLast,tcb_Clear,this);
		mRoot = NULL;
		mCount=0;
		mHeight=0;
}

void CBinTree::Insert(BinTreeNode* pNode)
{
  if (mRoot==NULL)
  {
	  mRoot = pNode;
	  mCount = 1;
	  mHeight = 1;
	  mRoot->SetParent(NULL);
  }
  else
  {
	  int lHeightTmp = 1;

      lHeightTmp += InsertRecursively(mRoot,pNode);
	  mCount++;

	  if (lHeightTmp > mHeight)
		  mHeight = lHeightTmp;
  }

}

int CBinTree::InsertRecursively(BinTreeNode* mParent,BinTreeNode* mNewNode)
{
	int returnValue = 1;

	if (mNewNode < mParent)
	{
		if (mParent->GetLeftChild()==NULL)
		{
			// No left child? Okie then, mNewNode is the new left child 
			mParent->SetLeftChild(mNewNode);
			mNewNode->SetParent(mParent);
		}
		else
		{
			returnValue += InsertRecursively(mParent->GetLeftChild(),mNewNode);
		}
	}
	else if (mNewNode > mParent)
	{
		if (mParent->GetRightChild()==NULL)
		{
			// No right child? Okie then, mNewNode is the new right child 
			mParent->SetRightChild(mNewNode);
			mNewNode->SetParent(mParent);
		}
		else
		{
			returnValue += InsertRecursively(mParent->GetRightChild(),mNewNode);
		}
	}

	else
	{
		// Duplicate!!! Already in tree
		returnValue = 0;
	}
	return (returnValue);

}
void CBinTree::TraverseAscending(void)
{
	Traverse(CBinTree::Ascending,callback_Find,mRoot);
}

void CBinTree::TraverseDescending(void)
{
	Traverse(CBinTree::Descending,callback_Find,mRoot);
}
void CBinTree::PrintStuff(void)
{
	Traverse(CBinTree::Ascending,callback_PrintStuff,mRoot);
	
}

void CBinTree::Traverse(TraverseOrder to, TraverseCallBack func, void* pParam)
{
  mFunc = func;
  mParam = pParam;
  pCBinTreeInstance = this;

  switch(to)
  {
  case Ascending:
    DoTraverse_Ascending(mRoot);
	break;
  case Descending:
    DoTraverse_Descending(mRoot);
	break;
  case ParentFirst:
    DoTraverse_ParentFirst(mRoot);
	break;
  case ParentLast:
    DoTraverse_ParentLast(mRoot);
	break;
  default:
	  ASSERT(FALSE);
  }

}

void CBinTree::DoTraverse_Ascending(BinTreeNode* pNode)
{
	if (!pNode)
		return;

	DoTraverse_Ascending(pNode->GetLeftChild());
	(pCBinTreeInstance->*mFunc)(pNode,mParam);
	//mFunc(pNode,mParam);
	DoTraverse_Ascending(pNode->GetRightChild());
}

void CBinTree::DoTraverse_Descending(BinTreeNode* pNode)
{
	if (!pNode)
		return;

	DoTraverse_Descending(pNode->GetRightChild());
	(pCBinTreeInstance->*mFunc)(pNode,mParam);
	//mFunc(pNode,mParam);
	DoTraverse_Descending(pNode->GetLeftChild());
}

void CBinTree::DoTraverse_ParentFirst(BinTreeNode* pNode)
{
	if (!pNode)
		return;

	(pCBinTreeInstance->*mFunc)(pNode,mParam);
	//mFunc(pNode,mParam);
	DoTraverse_ParentFirst(pNode->GetLeftChild());
	DoTraverse_ParentFirst(pNode->GetRightChild());
}

void CBinTree::DoTraverse_ParentLast(BinTreeNode* pNode)
{
	if (!pNode)
		return;

	DoTraverse_ParentLast(pNode->GetLeftChild());
	DoTraverse_ParentLast(pNode->GetRightChild());
	(pCBinTreeInstance->*mFunc)(pNode,mParam);
	//mFunc(pNode,mParam);
}

BinTreeNode* CBinTree::Find(BinTreeNode* pSearchNode)
{
	mpSearchNode = pSearchNode;
	mComparisons = 0;
	return DoTraverse_Find(mRoot, pSearchNode );
}

// DoTraverse_Find will, unlike the other DoTraverse_xxx, not 
// go through _all_ nodes, but stop when node is found or 
// is decided can't be found.

BinTreeNode* CBinTree::DoTraverse_Find(BinTreeNode* node,
									   BinTreeNode* pSearchNode)
{
  // Reached a dead end, node couldn't be found.
  if (!node)
	  return NULL;

  mComparisons++;
  //int iComp = Compare(node,mpSearchNode);

  // Found the node we were looking for, return it.
  //if (iComp == 0)
  if (node == pSearchNode)
	  return node;

  // node > mpSearchNode, look if it is by the left 
  //if (iComp > 0)
  if (node > pSearchNode)
	  return DoTraverse_Find(node->GetLeftChild(),pSearchNode);
  
  // node < mpSearchNode, look if it is by the right
  // if (iComp < 0)
  return DoTraverse_Find(node->GetRightChild(),pSearchNode);
}

// tcb_Balance: TraverseCallBack
// Add the node into the array.
// pParam is the tree (so we can get the array)
void CBinTree::tcb_Balance(BinTreeNode* pNode,void* pParam)
{
	CBinTree* pTree = (CBinTree*) pParam;
	pTree->mBalArray[pTree->mBalArrayCount] = pNode;
    pTree->mBalArrayCount++;
}

// Bring balance to the force.
void CBinTree::Balance()
{
    // Setup an array that will hold the nodes
	mBalArray = new BinTreeNode*[mCount];
	mBalArrayCount=0;

	// Put the nodes into the array in ascending order (ie sorted)
    Traverse(Ascending,tcb_Balance,this);

    // Clarifying the array now holds all the elements
	ASSERT(mCount == mBalArrayCount);

	// Remove the nodes from the tree (easily done).
	// We will put 'em back soon enough.
	CBinTree::Clear();


	// Reset the nodes so they don't have any children,
	// they will be given new as nodes get inserted back into to the tree.
	for (int i=0;i<mBalArrayCount;i++)
	{
		mBalArray[i]->SetLeftChild(NULL);
		mBalArray[i]->SetRightChild(NULL);
		mBalArray[i]->SetParent(NULL);
	}

	// Insert the nodes back to the tree in a balanced fashion.
	GetFromOrderedArray(0,mBalArrayCount-1);

    // Clarifying all elements have been inserted back from the array
	ASSERT(mCount == mBalArrayCount);

	delete mBalArray;
}

// DoBalance.
// Insert the node in the middle position between 
// low and hi from the mBalArray array. 
// Recurse and the array elements < middlePos and > middlePos.
void CBinTree::GetFromOrderedArray(int low, int hi)
{

  if (hi<low)
	  return;

  int middlePos;
  middlePos = low+(hi-low)/2;

  Insert(mBalArray[middlePos]);

  GetFromOrderedArray(low,middlePos-1);
  GetFromOrderedArray(middlePos+1,hi);
}

BOOL CBinTree::RemoveNode(BinTreeNode* pSearchNode)
{
  BinTreeNode* pNode = Find(pSearchNode);
  if (!pNode)
	  return FALSE;

  int iCount = mCount;
  
  BinTreeNode* pParent = pNode->GetParent();

  // Ok, so it has a parent, then we'll simply just disconnect it.
  if (pParent)
  {
	  if (pParent->GetLeftChild() == pNode)
	  {
		  pParent->SetLeftChild(NULL);
	  }
	  else
	  {
		  ASSERT(pParent->GetRightChild() == pNode);
		  pParent->SetRightChild(NULL);
	  }
  }
  else
  {
	  // No parent? Then we're deleting the root node.
	  ASSERT(pNode == mRoot);
	  mRoot = NULL;
  }

  // Disconnected, now we reconnect its children (if any)
  // just by adding them as we add any other node. Their
  // respective children will come along, since Insert doesnt
  // tamper with the inserted node's children.
  if (pNode->GetLeftChild())
	  Insert(pNode->GetLeftChild());
  if (pNode->GetRightChild())
	  Insert(pNode->GetRightChild());

  mCount = iCount-1;

  // Give the subclass a chance to do stuff to the removed node.
  OnRemoveNode(pNode);
  return TRUE;

}

