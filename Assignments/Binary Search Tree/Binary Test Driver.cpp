    
//This is the basic binary tree code. The function include are: add, print,
//sort, and delete a interger.


#include <iostream>
#include <string>
#include "tree.h"

using std::cin;
using std::cout;
using std::endl;


void main()
{
    char answer;
    int num;
    int success=0;

    node *root=NULL;

    tree test;

    for(int i=5; i>0; i++)    //set a for loop to keep the program run
    { //main menu
        cout << "This is the basic tree structure" << endl;
        cout << endl;
        cout << "Enter 'A' for add a new number" << endl;
        cout << "Enter 'D' for delete a number" << endl;
        cout << "Enter 'P' for print all the number" << endl;
        cout << "Enter 'S' for search for number" << endl;
        cout << "Enter 'Q' for quit the program" << endl;

        cout << endl;
        cout << "Please enter your choose of A or P or Q:";

        cin >> answer;

        //the add function
        if((answer=='a')||(answer=='A'))
        {
            cout << "Please enter a new number: ";
            cin >> num;
            success=test.add(root, num, success);    //call the function

            if(success==1)                          //determind if success or fail
                cout << "Add success" << endl;
            else
                cout << "Add fail" << endl;
        }

        //the delete function
        else if((answer=='d')||(answer=='D'))
        {
            cout << "delete Function \n";
            cout << "Enter a number to be delete: ";
            cin >> num;

            success=test.del(root, num, success);

            if(success==1)
                cout << "delete success" << endl;
            else
                cout << "delete fail" << endl;
        }

        //the print function
        else if((answer=='p')||(answer=='P'))
        {
            cout << "Print Function \n";
            success=test.print(root, success);

            if(success==1)
                cout << "print success" << endl;
            else
                cout << "print fail" << endl;
        }

        //the search function
        else if((answer=='s')||(answer=='S'))
        {
            cout << "search Function \n";
            cout << "Enter a number to be search: ";
            cin >> num;
            success=test.search(root, num, success);

            if(success==1)
                cout << "search success" << endl;
            else
                cout << "search fail" << endl;
        }

//if the the answer equal to Q, then set the for loop to fail that will quit the program
        else if((answer=='q')||(answer=='Q'))
            i=0;

        else
            cout << "Error, Please enter A or P or Q" << endl; //error checking
        i--; //make not grow any larger

    } //for loop
}
