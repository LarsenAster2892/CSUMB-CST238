#include "BinTreeNode.h"
#include "StringIntTree.h"

#ifndef BINTREE_h
#define BINTREE_h

class CBinTree;
typedef void (CBinTree::*TraverseCallBack)(BinTreeNode*,void*);  


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class used to describe Binary Tree
//
//
//===================================================================

class CBinTree
{
	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:

	
		BinTreeNode* mRoot;    // The top node. NULL if empty.

		// Used in traversing
		CBinTree * pCBinTreeInstance;

		TraverseCallBack mFunc;
		void* mParam;
		BinTreeNode* mpSearchNode;

		int mComparisons;
		int mCount;
		int mHeight;
		void tcb_Balance(BinTreeNode* pNode,void* pParam);

	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:

		// Remove all nodes without deleting them.
		// Not really hard now is it. 
		void Clear();

		// Override if you want to take some special actions when a 
		// node gets removed from the tree.
		virtual void OnRemoveNode(BinTreeNode* pNode) {};
		
		// Called by Insert.
		int InsertRecursively(BinTreeNode* pParent,BinTreeNode* pNewNode);


		// Called by Traverse. All similar except for the order in which they call the children.
		void DoTraverse_Ascending(BinTreeNode* pNode);
		void DoTraverse_Descending(BinTreeNode* pNode);
		void DoTraverse_ParentFirst(BinTreeNode* pNode);
		void DoTraverse_ParentLast(BinTreeNode* pNode);


		// Called by Find. Does the real work.
		virtual BinTreeNode* DoTraverse_Find(BinTreeNode* pNode,
											 BinTreeNode* pSearchNode);

		// Called by Balance. 
		void GetFromOrderedArray(int low, int hi);
	
		virtual void callback_PrintStuff(BinTreeNode* p,void* pParam) = 0;
		virtual void callback_Find(BinTreeNode* p,void* pParam) = 0;
		virtual void tcb_Clear(BinTreeNode* p, void* pParam) = 0;
	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	public:

		// TraverseOrder. Input parameter to the Traverse function.
		// Specifies in what way the tree should be traversed.
		// Ascending   : 1,2,3,4,5....
		// Descedning  : 9,8,7,6,5....
		// ParentFirst : The parent node will be handeled before its children.
		//               Typically use when the structure is saved, so that
		//               the (possibly balanced) structure wont be altered.
		// ParentLast  : The parent node will be handeled after its children.
		//               Typically use when tree is deleted; got to delete the 
		//               children before deleting their parent.
		enum TraverseOrder { Ascending=0,Descending,ParentFirst,ParentLast };

		//
		// ============= CONSTRUCTOR =====================
		//
		CBinTree();

	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~CBinTree();

		// Insert. Adds a node to the tree at the right place.
		void Insert(BinTreeNode* pNode);

		// Return the first BinTreeNode in the tree where
		// Compare (node,pSearchNode)==0, or NULL if not found.
		BinTreeNode* Find(BinTreeNode* pSearchNode);

		// Remove a node.Return non-zero if the node could
		// be found in the tree.
		// The first node where Compare (node,pSearchNode)==0
		// gets zapped.
		BOOL RemoveNode(BinTreeNode* pSearchNode);

		// Returns the number of comparisons required for the last
		// call to Find. Gives a hint on how balanced the tree is.
		int GetComparisons() const { return mComparisons; }

		// Traverse will call the supplied function, func,  for every node in the tree,
		// passing it a pointer to the node, so you can act opon it.
		// func: The callback function, like void somefunction(BinTreeNode*,void*);
		// The pParam will also be passed to the function and is a pointer to something.
		// You decide to what, or ignore if you dont need it.
		void Traverse(TraverseOrder to, TraverseCallBack func, void* pParam=NULL);

		//void TraverseAscending(void);
		//void PrintStuff(BinTreeNode* p,void* pParam);

		// Number of nodes in the tree.
		int GetCount() const { return mCount; }

		// The height of the tree, indicates how balanced it is.
		// The height is the maximum number of comparisons needed to be
		// made (worst case) when searching for an element.
		int GetHeight() const { return mHeight; }

		// Balance minimizes the height, optimizing it.
		void Balance();

		// These two thingies are temp. stuff used in balancing.
		BinTreeNode** mBalArray; // Array of pointers to nodes
		int mBalArrayCount; 

		
		void TraverseAscending(void);
		void TraverseDescending(void);
		void PrintStuff(void);
};
#endif 

