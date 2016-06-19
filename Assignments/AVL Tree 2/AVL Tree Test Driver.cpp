#include <iostream>
#include "AVLTree.h"

int main() {
    int i;
    int data [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    AvlTree *tree = new AvlTree();
    for (i = 0; i < 10; i++) {
	tree->insert(data + i);
    }
    return 0;
}

