
#include "tree.h"


struct node
{
    int num;
    node *left;
    node *right;
};



tree::tree()
{
    // cout << "Constructor call \n";
    root = NULL;
}

tree::~tree()
{
    // cout << "destructor call" << endl;
    destructor(root); //call the destructor function that will delete all the data
}

void tree::destructor(node *&root)
{
    if(root != NULL)
    {
        destructor(root->left);
        destructor(root->right);
        cout << "delete num" << endl;

        delete root;
    }
    else
        return;
}



//this is the add function, that will add number to left or right of binary tree.
//it will call the add function it self to do the adding.
int tree::add(node *&root, int num, int success)
{
    if(root==NULL) //if is NULL make a new node and copy number to the new node
    {
        root=new node; //make new node
        root->num=num; //copy number
        root->left=NULL; //set the children to NULL
        root->right=NULL;
        success=1;
        return success; //return success
    }

    else if(num < root->num) //if num is less then the current num
        add(root->left, num, success); //then go to the left side of binary tree
    else
        add(root->right, num, success); //else go to the right side of binary tree
return 1;
}

//this is the print function, it will print all the number in the binary tree in
//order.
int tree::print( node *&root, int success)
{
    if(root!=NULL)     //if the tree is not empty
    {
        print(root->left, success); //travil to the left
        cout << root->num << " "; //print out the number
        print(root->right, success); //then to the right
        success=1;
    }
    else
        success=0; //return success or fail
    return success;
}

//this is the search function. it was used binary search
int tree::search(node*&root, int num, int success)
{
    if(root==NULL)     //if the tree is empty, then print out an error message
    {
        cout << num << " was not found" << endl;
        return success=0;
    }

    else if(num == root->num) //if the match was the root, print out the num
    {
        cout << root->num << " was found" << endl;
        return success =1;
    }

    else if(num < root->num) //else check if the num was less the root
        search(root->left, num, success); //if it is less then root go to left

    else
        search(root->right, num, success); //if it is great then root go to right
}


//this is the delete function
int tree::del(node*&root, int num, int success)
{
    node *temp=NULL;

    if(root==NULL) //if the tree was empty, print out an error message
    {
        cout << num << " was not found" << endl;
        return success=0;      //return fail
    }

    //if a match at the root
    else if(num == root->num) //if it was the first data (node)
    {
        if(root->right==NULL) //check if it has right child. If it has no right child
        {
            temp=root; //set temp to root
            root=root->left; //root move to the left child
            delete temp; //delete temp, this is delete the root
            return success=1;     //return success
        }

        //if it have right child or both of the right and left child is not NULL
        else if((root->right)||((root->left)&&(root->right))!=NULL)
        {
            node *temp2; //make a new pointer
            temp=root; //make temp to root
            temp2=root->left; //set temp2 to the left side of the tree
            root=root->right; //root travel to the right
            del_root_two_child(root, num, success, temp, temp2);
        }
        return success =1;
    }

    else
        searchDel(root, num, success); //else is the match was not at the root

}

//search for a match to delete
int tree::searchDel(node*&root, int num, int success)
{

    node *temp;

    if(root==NULL) //if there isn't a match
    {
        success=0;
        return success=0; //return fail
    }

    else //if a match
    {
        if(root->num > num) //go to the left of the tree
            searchDel(root->left, num, success);
        else if(root->num < num) //go to the right of the tree
            searchDel(root->right, num, success);
        else //find a match
        {
            if((root->left==NULL)&&(root->right==NULL)) //del when both child is NULL
            {
                delete root; //delete node
                root=NULL;
                return success=1;
            }

            else if(root->right==NULL) //if there only left child
            {
                temp=root; //temp equal to parent
                root=root->left; //grandson connect to grandparent
                delete temp;
                return success=1; //delete parent
            }

            else if(root->left==NULL) //if there only right child
            {
                temp=root;
                root=root->right;
                delete temp;
                return success=1;
            }         //else loop

            else                  //if it have two children
            {
                node *temp2=NULL;
                temp=root; //set the left side of the tree to temp2
                temp2=root->left;
                root=root->right; //root travel to the right side
                del_two_child(root, num, success, temp, temp2); //find the farest left data
            }

        } //else loop
    }//if root not equal to NULL loop

    //return success;
} //function loop

//this is the delete node with two children
int tree::del_two_child(node *&root, int num, int success, node *&temp, node *&temp2)
{
    if(root!=NULL)
    {
        del_two_child(root->left, num, success, temp, temp2);//travel to the farest left data
    }
    else
    {
        temp=root;                      //copy data to root
        root=new node;                      //make a new node
        root=root->left;
        root=temp2;                      //connet the left side of the tree will the root
        return success=1;
    }
    return success=1;
}

//if the root have children then use this function to delete the root
int tree::del_root_two_child(node *&root, int num, int success, node *&temp, node *&temp2)
{

    if(root!=NULL)
    {
        del_root_two_child(root->left, num, success, temp, temp2);//travel to the farest left
    }
    else
    {
        temp=root;                  //copy the data
        root=new node;
        root=root->left;
        root=temp2;              //connect the left side of the tree.
        return success=1;
    }
    return success=1; //return success
}
 

