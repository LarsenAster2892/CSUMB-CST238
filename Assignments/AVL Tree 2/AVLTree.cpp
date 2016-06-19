/*
 * avltree.cpp
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "AVLTree.h"

using namespace std;

int AvlTree::nextKey = 0;

AvlTree::AvlTree(void (*destroy)(void *data)) : BiTree(destroy) {}

AvlTree::~AvlTree() {
    //
}

void AvlTree::rotLeft(AvlNode **node) {
    AvlNode *child, *grandchild;

    child = (AvlNode*) (*node)->left;

    if (child->bfact == AVL_LH) {
	/* perform an LL rotation */
	cout << "LL" << endl;
	(*node)->left = child->right;
	child->right = *node;
	(*node)->bfact = child->bfact = AVL_B;
	*node = child;
    } else {
	/* perform an LR rotation */
	cout << "LR" << endl;
	grandchild = (AvlNode *) child->right;
	child->right = grandchild->left;
	grandchild->left = child;
	(*node)->left = grandchild->right;
	grandchild->right = *node;

	switch (grandchild->bfact) {
	    case AVL_LH:
		(*node)->bfact = AVL_RH;
		child->bfact = AVL_B;
		break;
	    case AVL_B:
		(*node)->bfact = AVL_B;
		child->bfact = AVL_B;
		break;
	    case AVL_RH:
		(*node)->bfact = AVL_B;
		child->bfact = AVL_LH;
		break;
	}

	grandchild->bfact = AVL_B;
	*node = grandchild;
    }
    return;
}


void AvlTree::rotRight(AvlNode **node) {
    AvlNode *child, *grandchild;

    child = (AvlNode*) (*node)->right;

    if (child->bfact == AVL_RH) {
	/* perform an RR rotation */
	cout << "RR" << endl;
	(*node)->right = child->left;
	child->left = *node;
	(*node)->bfact = child->bfact = AVL_B;
	*node = child;
    } else {
	/* perform an RL rotation */
	cout << "RL" << endl;
	grandchild = (AvlNode *) child->left;
	child->left = grandchild->right;
	grandchild->right = child;
	(*node)->right = grandchild->left;
	grandchild->left = *node;

	switch (grandchild->bfact) {
	    case AVL_LH:
		(*node)->bfact = AVL_B;
		child->bfact = AVL_RH;
		break;
	    case AVL_B:
		(*node)->bfact = AVL_B;
		child->bfact = AVL_B;
		break;
	    case AVL_RH:
		(*node)->bfact = AVL_LH;
		child->bfact = AVL_B;
		break;
	}

	grandchild->bfact = AVL_B;
	*node = grandchild;
    }
    return;
}

bool AvlTree::ins(AvlNode *child, AvlNode **node, bool *balanced) {
    bool retval;

    if ((*node) == NULL) {
	/* tree is empty */
	root = child;
	size++;
    } else {
	/* tree is not empty */

	if (child->key < (*node)->key) {
	    /* go to the left */

	    if ((*node)->left == NULL) {
		(*node)->left = child;
		size++;
		*balanced = false;
	    } else {
		retval =  ins(child, &((AvlNode *) (*node)->left), balanced);
		if (! retval) {
		    return retval;
		}
	    }

	    if (!(*balanced)) {
		switch ((*node)->bfact) {
		    case AVL_LH:
			rotLeft(node);
			*balanced = true;
			break;
		    case AVL_B:
			(*node)->bfact = AVL_LH;
			break;
		    case AVL_RH:
			(*node)->bfact = AVL_B;
			*balanced = true;
			break;
		}
	    }

	} else if (child->key > (*node)->key) {
	    /* go to the right */

	    if ((*node)->right == NULL) {
		(*node)->right = child;
		size++;
		*balanced = false;
	    } else {
		retval =  ins(child, &((AvlNode *) (*node)->right), balanced);
		if (! retval) {
		    return retval;
		}
	    }

	    if (!(*balanced)) {
		switch ((*node)->bfact) {
		    case AVL_LH:
			(*node)->bfact = AVL_B;
			*balanced = true;
			break;
		    case AVL_B:
			(*node)->bfact = AVL_RH;
			break;
		    case AVL_RH:
			rotRight(node);
			*balanced = 1;
			break;
		}
	    }
	} else {
	    /* duplicate key */
	    return false;
	}
    }
    return true;
}


bool AvlTree::insert(const void *data) {
    AvlNode *child;
    bool balanced = false;

    if ((child = new AvlNode((int) data, data)) == NULL) {
	return false;
    } else {
	return ins(child, &((AvlNode *) root), &balanced);
    }
}


bool AvlTree::remove(const void *data) {
    return true;
}


bool AvlTree::lookup(void **data) {
    return true;
}



