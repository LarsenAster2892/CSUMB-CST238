#include <iostream.h>
#include <string.h>
#include "tree.h"

void PrintWord(word & in)
{
	if (in.isEmpty())
	{
		cout << endl;
	}
	else
	{
		cout << in.name <<  " ";
	}
}

int main()
{
	tree wordtree;

	word w1,w2,w3,w4,w5;

	strcpy(w1.name, "one");
	strcpy(w2.name, "two");
	strcpy(w3.name, "three");
	strcpy(w4.name, "four");
	strcpy(w5.name, "five");

	wordtree.Insert(w1);
	wordtree.Insert(w2);
	wordtree.Insert(w3);
	wordtree.Insert(w4);
	wordtree.Insert(w5);

	wordtree.TraverseInOrder(PrintWord);

	return 0;
}
