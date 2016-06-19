#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;

struct node;

class tree
{
    public:

        tree();
        ~tree();

        void destructor(node *&root); //subfunction for destructor
        int add(node *&root, int num, int success);     //add function
        int print( node *&root, int success);         //print function
        int search(node *&root, int num, int success);    //search function

        //all these function are for delete only
        int del(node *&root, int num, int success);
        int searchDel(node *&root, int num, int success);
        int del_two_child(node *&root, int num, int success, node *&temp, node *&temp2);
        int del_root_two_child(node *&root, int num, int success, node *&temp, node*&temp2);

    private:
        node * root;
};
