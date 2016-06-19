//********************************************************
// File Name   : StringBinTreeNode.h   
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : December 10, 2003 (5:30 PM)
// Description : Header file for StringBinTreeNode Class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include "BinaryTree.h"
#include "StringBinTreeNode.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


#ifndef STRINGBINARYTREE_h
#define STRINGBINARYTREE_h
//===================================================================
//
//                      CLASS DEFINITION
//
// Brief Description:  A DataContainer Class 
//
// Base Classes: BinaryTree
//
//===================================================================

//
// --- CONSTANTS -----
// 
//const int DEFAULT_SIZE = 10;		// The number of elements in the arrary

class StringBinaryTree : public BinaryTree
{
	private:
	//
	// -- data members -----
	//


	//
	// -- Member Methods -----
	//


	

	public:
		//
		// ============= CONSTRUCTOR =====================
		//
		StringBinaryTree();


		//
		// ============= DESTRUCTOR =====================
		//
		virtual ~StringBinaryTree();
		
		//
		// ============= COPY CONSTRUCTOR =====================
		//

		//
		// ============= ACCESSORS =====================
		//
		
		//
		//========= Member Methods ==================
		//
		  void Add(string str);

		  bool Delete(string str);

		  StringTreeNode* FindByString(string str);

		void DeleteNode(/* IN    */  BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
			//       to Tree Node
			// Post: Tree/SubTree node is deleted 
			//-------------------------------------------------
		
		void PrintNode(/* IN    */  BinTreeNode* pNode);
			//-------------------------------------------------
			// Pre : pNode is assigned and is of type pointer 
		    //       to Tree Node
			// Post: Tree/SubTree node is printed 
			//-------------------------------------------------


		int InsertRecursively(/* IN    */  BinTreeNode* pParent,
			                  /* IN    */  BinTreeNode* pNewNode);
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


		
		BinTreeNode* FindRecursively(/* IN    */  BinTreeNode* pNode,
			                         /* IN    */  BinTreeNode* pSeachNode);
			//-------------------------------------------------
			// Pre : pNode is assigned.
			// Post: if a node with the data in pNode is  found in tree         
			//			returns pointer to that node
			//       else
		    //          returns null
			//  (PREORDER TRAVERSAL - LEFT, RIGHT , PARENT)
			//-------------------------------------------------
		 bool IsEqual(BinTreeNode* pNode1, BinTreeNode* pNode2);
		 bool IsLessThan(BinTreeNode* pNode1, BinTreeNode* pNode2);
		 bool IsGreaterThan(BinTreeNode* pNode1, BinTreeNode* pNode2);
};

#endif