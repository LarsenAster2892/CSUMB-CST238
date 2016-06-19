#ifndef _STRINGTREE_H_
#define _STRINGTREE_H_

#include "BinTree.h"
//#include "BinTreeNode.h"
#include "StringBinTreeNode.h"
#include <iostream>
using std::cout;
using std::endl;


// CStringIntTree. A binary tree of StringTreeNode nodes.
class CStringIntTree : public CBinTree
{
protected:
  // Overrides the pure virtual compare function.
  // and compares the strings of the nodes.
  //int Compare(BinTreeNode* p1,BinTreeNode* p2) const;
  //BinTreeNode* DoTraverse_Find(BinTreeNode* pNode,
	//					       BinTreeNode* pSearchNode);

  virtual void OnRemoveNode(BinTreeNode* pNode) { delete (StringTreeNode*)pNode; };
public:
  // Destructor
	~CStringIntTree() { Clear(); };
  
  // Function to directly add StringTreeNode:s to the tree.
  void Add(LPCTSTR str);

  BOOL DeleteByString(LPCTSTR str);

  // Load the contents from a file.
  void Load(LPCTSTR fileName);

  // Delete all nodes (not only remove them from the tree)
  ///void Clear();

  // FindByString. Returns the StringTreeNode matching the
  // given string str or NULL if couldn't be found.
  StringTreeNode* FindByString(string str);
  void callback_PrintStuff(BinTreeNode* p,void* pParam);
  void callback_Find(BinTreeNode* p,void* pParam);
  void tcb_Clear(BinTreeNode* p, void* pParam);
};

#endif // _STRINGTREE_H_

