/*
 * bitree.h
 */

#ifndef BITREE_H
#define BITREE_H

#include <cstdlib>


class BiTreeNode {
    public:
	BiTreeNode(const void *data = NULL) {
	    this->data = (void *) data;
	    left = NULL;
	    right = NULL;
	}

	virtual ~BiTreeNode() {}

	void* getData() {
	    return data;
	}

	BiTreeNode* getLeft() {
	    return left;
	}

	BiTreeNode* getRight() {
	    return right;
	}

	void setLeft(BiTreeNode* node) {
	    left = node;
	}

	void setRight(BiTreeNode* node) {
	    right = node;
	}

	bool isLeaf() const {
	    return (left == NULL && right == NULL);
	}

    protected:
	void *data;
	BiTreeNode *left;
	BiTreeNode *right;
};



class BiTree {
    public:
	
	/*
	 * Constructor: initializes the tree.  The "destroy" argument
	 * provides a way to free dynamically allocated data when the
	 * destructor is called.  For a binary tree containing data that
	 * should not be freed, "destroy" should be set to NULL.
	 * Complexity: O(1)
	 */
	BiTree(void (*destroy)(void* data) = NULL);

	
	/*
	 * Destructor: destroys the linked list.  This operation removes
	 * all elements from the binary tree and calls the function
	 * "destroy()" for each element as it is removed, provided that
	 * "destroy" was not set to NULL.
	 * Complexity: O(size)
	 */
	virtual ~BiTree();

	
	/*
	 * merge():
	 * Complexity: O(1)
	 */
	static BiTree* merge(BiTree *left, BiTree *right, const void *data);

	
	/*
	 * insLeft():
	 * Complexity: O(1)
	 */
	bool insLeft(BiTreeNode *node, const void *data);

	
	/*
	 * insRight():
	 * Complexity: O(1)
	 */
	bool insRight(BiTreeNode *node, const void *data);

	
	/*
	 * remLeft():
	 * Complexity: O(size of the left subtree of the node)
	 */
	bool remLeft(BiTreeNode *node);

	
	/*
	 * remRight():
	 * Complexity: O(size of the right subtree of the node)
	 */
	bool remRight(BiTreeNode *node);

	
	/*
	 * remAll():
	 * Complexity: O(size)
	 */
	void remAll();

	
	/*
	 * getRoot(): returns the node at the root of the tree.
	 * Complexity: O(1)
	 */
	BiTreeNode* getRoot();

	
	/*
	 * getSize(): returns the number of nodes in the tree.
	 * Complexity: O(1)
	 */
	int getSize();



    protected:
	BiTreeNode *root;
	int size;
	void (*destroy)(void *data);
};

#endif


