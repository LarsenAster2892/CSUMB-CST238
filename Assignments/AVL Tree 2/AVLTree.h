/*
 * avltree.h
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using std::cout;
using std::endl;

#include "bitree.h"

using namespace std;

#define AVL_LH  1
#define AVL_B   0
#define AVL_RH -1

class AvlNode : public BiTreeNode {
    friend class AvlTree;

    public:
	virtual ~AvlNode() {}
	const int key;

    private:
	AvlNode(int newKey = 0, const void *data = NULL) :
		BiTreeNode(data), key(newKey) {
	    bfact = AVL_B;
	    cout << key << endl;
	}

	int bfact;
};

class AvlTree : public BiTree {
    public:
	AvlTree(void (*destroy)(void *data) = NULL);
	~AvlTree();
	bool insert(const void *data);
	bool remove(const void *data);
	bool lookup(void **data);
    private:
	bool ins(AvlNode *child, AvlNode **node, bool *balanced);
	void rotLeft(AvlNode **node);
	void rotRight(AvlNode **node);
	int (*genKey)(void *data);
	static int nextKey;
};

#endif


