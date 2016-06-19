/*
 * bitree.cpp
 */

#include <cstdlib>
#include <cstring>

#include "bitree.h"

using namespace std;


BiTree::BiTree(void (*destroy)(void* data)) {
    root = NULL;
    size = 0;
    this->destroy = destroy;
}


BiTree::~BiTree() {
    remAll();
    memset(this, 0, sizeof(BiTree));
}


BiTree* BiTree::merge(BiTree *left, BiTree *right, const void *data) {
    BiTree *tree = new BiTree(left->destroy);
    if (! tree->insLeft(NULL, data)) {
	delete tree;
	tree = NULL;
    } else {
	tree->root->setLeft(left->root);
	tree->root->setRight(right->root);
	tree->size = tree->size + left->size + right->size;

	/* do not let the original trees to access the merged nodes */
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;
    }

    return tree;
}


bool BiTree::insLeft(BiTreeNode *node, const void *data) {

    if (node == NULL) {

	if (size > 0) {
	    /* allow insertion at the root only in an empty tree */
	    return false;
	}
	root =  new BiTreeNode(data);

    } else {

	if (node->getLeft() != NULL) {
	    /* allow insertion only at leafs */
	    return false;
	}
	node->setLeft(new BiTreeNode(data));
    }

    size++;
    return true;
}


bool BiTree::insRight(BiTreeNode *node, const void *data) {
    if (node == NULL) {

	if (size > 0) {
	    /* allow insertion at the root only in an empty tree */
	    return false;
	}
	root =  new BiTreeNode(data);

    } else {

	if (node->getRight() != NULL) {
	    /* allow insertion only at leafs */
	    return false;
	}
	node->setRight(new BiTreeNode(data));
    }

    size++;
    return true;
}


bool BiTree::remLeft(BiTreeNode *node) {
    BiTreeNode *child;
    bool retval;

    if (size == 0 || node == NULL) {
	return true;
    }

    child = node->getLeft();
    retval = remLeft(child) && remRight(child);
    if (destroy != NULL) {
	destroy(child->getData());
    }
    delete child;
    child = NULL;
    size--;
    return retval;
}


bool BiTree::remRight(BiTreeNode *node) {
    BiTreeNode *child;
    bool retval;

    if (size == 0 || node == NULL) {
	return true;
    }

    child = node->getRight();
    retval = remLeft(child) && remRight(child);
    if (destroy != NULL) {
	destroy(child->getData());
    }
    delete child;
    child = NULL;
    size--;
    return retval;
}


void BiTree::remAll() {
    if (size == 0) {
	return;
    }
    remLeft(root);
    remRight(root);
    if (destroy != NULL) {
	destroy(root->getData());
    }
    delete root;
    root = NULL;
    size = 0;
    return;
}


BiTreeNode* BiTree::getRoot() {
    return root;
}


int BiTree::getSize() {
    return size;
}



