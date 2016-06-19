#include "stdafx.h"
#include "StringIntTree.h"

// ---------------------- CStringIntTree --------------------------

//int CStringIntTree::Compare(BinTreeNode* p1,BinTreeNode* p2) const
//{
//	return strcmp(
//		     ((StringTreeNode*)p1)->GetString(),
//			 ((StringTreeNode*)p2)->GetString()
//			 );
//}

void CStringIntTree::Add(LPCTSTR str)
{
	Insert( new StringTreeNode(str) );
}

BOOL CStringIntTree::DeleteByString(LPCTSTR str)
{
  StringTreeNode searchNode(str); // The int part of the node is
                                        // ignored in comparison

  return RemoveNode(&searchNode);
}

StringTreeNode* CStringIntTree::FindByString(string str)
{
  StringTreeNode searchNode(str); // The int part of the node is
                                        // ignored in comparison

  StringTreeNode* pRes = (StringTreeNode*) Find(&searchNode);
  return pRes;
}


// tcb_Clear : TraverseCallBack. Delete the node
void CStringIntTree::tcb_Clear(BinTreeNode* p, void* pParam)
{
  delete (StringTreeNode*)p;
}


//void CStringIntTree::Clear()
//{
//	// ParentLast, so child is deleted prior its parent
//	//Traverse(ParentLast,tcb_Clear,this);
//	CBinTree::Clear();
//}



void CStringIntTree::Load(LPCTSTR fileName)
{
  CFile f;
  VERIFY(f.Open(fileName,CFile::modeRead));

  Clear();

  int pos = 0;
  int size = f.GetLength();

  LPCTSTR str;
  int* pInt;

  char* buf = new char[size];

  f.Read(buf,size);  
  f.Close();

  while (pos<size)
  {
	  str = &buf[pos];
	  pInt= (int*)&buf[pos + strlen(str)+1];

	  Add(str);

	  pos+=strlen(str)+sizeof(int)+1;
  }

  delete [] buf;


}


//==========================================================
void CStringIntTree::callback_PrintStuff(BinTreeNode* p,void* pParam)
{
  StringTreeNode* pNode = (StringTreeNode*) p;
  cout << pNode <<  "\n";
}

void CStringIntTree::callback_Find(BinTreeNode* p,void* pParam)
{
	CStringIntTree* pTree = (CStringIntTree*)pParam;
	StringTreeNode* pNode = (StringTreeNode*) p;    
	
	StringTreeNode* pNodeFound;
	pNodeFound = pTree->FindByString(pNode->GetString());
	if (pNodeFound) 
	{
		cout << pNodeFound->GetString() 
			 << " found after " 
			 << pTree->GetComparisons() 
			 << " comparisons.\n";
	}
}


//BinTreeNode* CStringIntTree::DoTraverse_Find(BinTreeNode* node,
//									       BinTreeNode* SearchNode)
//{
//	StringTreeNode* pNode = (StringTreeNode*) node;    
//	StringTreeNode* pSearchNode = (StringTreeNode*) SearchNode;    
//
//  // Reached a dead end, node couldn't be found.
//  if (!pNode)
//	  return NULL;
//
//  //mComparisons++;
//  //int iComp = Compare(node,mpSearchNode);
//
//  // Found the node we were looking for, return it.
//  //if (iComp == 0)
//  if (pNode == pSearchNode)
//	  return node;
//
//  // node > mpSearchNode, look if it is by the left 
//  //if (iComp > 0)
//  if (pNode > pSearchNode)
//	  return DoTraverse_Find(pNode->GetLeftChild(),pSearchNode);
//  
//  // node < mpSearchNode, look if it is by the right
//  // if (iComp < 0)
//  return DoTraverse_Find(pNode->GetRightChild(),pSearchNode);
//}
