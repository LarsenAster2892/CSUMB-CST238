//********************************************************
// File Name   : BinaryTree.h       
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Header file for Binary Tree Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <iostream>
#include <iomanip>
#include "BinTreeNode.h"
//#include "StringIntTree.h"


#ifndef BINARYTREE_h
#define BINARYTREE_h


//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  Abstract Base Class used to describe a 
//                           Binary Tree
//
//
//===================================================================

class  BinaryTree
{
	//
	// -- PRIVATE DATA MEMBERS AND METHODS -----
	//
	private:
	    BinTreeNode * mRoot;        // The top node. NULL if empty.
		BinTreeNode * mpSearchNode; // Used for search.
	
		int mNodeCount;
		int mTreeHeight;

	
		void PrintRecursivelyAscending(/* IN    */  BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
		    //       to Tree Node
			// Post: Tree/SubTree is printed in ascending order 
		    //       by recursive calls
			//-------------------------------------------------

		void PrintRecursivelyDescending(/* IN    */  BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
		    //       to Tree Node
			// Post: Tree/SubTree is printed in descending order 
		    //       by recursive calls
			//-------------------------------------------------
		
		void PrintRecursivelyGraphic(/* IN    */  BinTreeNode* pNode,
							         /* IN    */  int Depth);
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
			//       to Tree Node.
			//       Depth is assigned is not < 0 and not 
			//       Greater than maximum tree depth
			// Post: Tree/SubTree is printed in reverse in-order
			//       by recursive calls
			//-------------------------------------------------
	
		BinTreeNode* FindMax(/* IN    */BinTreeNode* pSearchNode);

		bool RemoveNodeRecursive(BinTreeNode* pRoot, BinTreeNode* pSearchNode);
		
	//
	// -- PROTECTED DATA MEMBERS AND METHODS -----
	//
	protected:
		virtual void DeleteNode(/* IN    */  BinTreeNode* pNode) = 0;
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
		    //       to Tree Node
			// Post: Tree/SubTree node is deleted 
			//-------------------------------------------------
		

		virtual BinTreeNode* FindRecursively(/* IN    */  BinTreeNode* pNode,
			                                 /* IN    */  BinTreeNode* pSeachNode) = 0;
			//-------------------------------------------------
			// Pre : pNode is assigned.
			// Post: if a node with the data in pNode is  found in tree         
			//			returns pointer to that node
			//       else
		    //          returns null
			//  (PREORDER TRAVERSAL - LEFT, RIGHT , PARENT)
			//-------------------------------------------------
	
		virtual int InsertRecursively(/* IN    */  BinTreeNode* pParent,
			                          /* IN    */  BinTreeNode* pNewNode) = 0;
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
		
		virtual void PrintNode(/* IN    */  BinTreeNode* pNode) = 0;
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
		    //       to Tree Node
			// Post: Tree/SubTree node is printed 
			//-------------------------------------------------
		virtual bool IsEqual(BinTreeNode* pNode1, BinTreeNode* pNode2) = 0;
		virtual bool IsLessThan(BinTreeNode* pNode1, BinTreeNode* pNode2) = 0;
		virtual bool IsGreaterThan(BinTreeNode* pNode1, BinTreeNode* pNode2) = 0;


	//
	// -- PUBLIC DATA MEMBERS AND METHODS -----
	//
	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		BinaryTree();
	
		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~BinaryTree();

		//
		// =============  ENUMERATED TYPE (Embedded in Class) =====================
		//
	
		enum PrintOrderType {Ascending = 0, Descending, Graphic};
		
		//
		// ============= ACCESSORS =====================
		//
		int GetNodeCount(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: current value of number of nodes is returned
			//-------------------------------------------------

		int GetTreeHeight(void) const; 
			//-------------------------------------------------
			// Pre : none
			// Post: current value of Tree height is returned
			//-------------------------------------------------

		//
		// ============= MUTATORS =====================
		//


		//
		// ============= MEMBER METHODS =====================
		//

		virtual void Clear(void);
			//-------------------------------------------------
			// Pre : none
			// Post: count and height are reset
			//-------------------------------------------------

		
		
		void DeleteAllRecursively(/* IN    */  BinTreeNode* pNode);
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
	
		BinTreeNode* Find(/* IN    */BinTreeNode* pSearchNode);
			//-----------------------------------------------------------
			// Pre : pSearchNode is assigned and is of type BinTreeNode
			// Post: if a node with the data in pSearchNode is found in tree
			//			returns pointer to node
			//       else
		    //          returns NULL
			//----------------------------------------------------------
		
		void Insert(/* IN    */BinTreeNode* pNode);
			//-----------------------------------------------------------
			// Pre : pNode is assigned and is of type BinTreeNode
			// Post: if a node with the data in pNode is NOT found in tree         
			//			a tree will contain tree plus node
			//       else
		    //          return
			//----------------------------------------------------------

		void PrintTree(/* IN    */PrintOrderType PrintOrder);
			//-----------------------------------------------------------
			// Pre : PrintOrder is assigned 
			// Post: Tree is printed in the order specified by PrintOrder         
			//----------------------------------------------------------

		bool RemoveNode(BinTreeNode* pSearchNode);
			//-----------------------------------------------------------
			// Pre : pSearchNode is assigned and is of type BinTreeNode
			// Post: if a node with the data in pSearchNode is found in tree         
			//			it is removed from the tree
			//       else
		    //          return
			//----------------------------------------------------------


};

#endif