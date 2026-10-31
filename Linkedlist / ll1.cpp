#include<iostream>
//#include<conio>
//#include<process>
using namespace std;

class linkedlist
{
private:
    struct node
    {
        int data;
        node *link;
    } *start, *newnode, *temp; // structure variables

public:
    linkedlist(); // default constructor
    void insert(); // function prototype
    void display();
};

// Constructor definition outside the class
linkedlist::linkedlist() 
{
    start = NULL; // initialize the head node to NULL to show it is empty
}

void linkedlist::insert()
{
    int num;
    char ch = 'y';

    // do loop to read numbers from user until user enters any key except 'y'
    do 
    {
        cout << "Enter the number: ";
        cin >> num;

        // Creating a node (memory is allocated by new keyword)
        newnode = new node;
        newnode->data = num;    // assign value to node
        newnode->link = NULL;   // assign pointer part as NULL

        // Executes if the list is empty
        if (start == NULL)
        {
            // Pointing start, temp pointers to newnode
            start = temp = newnode;
        }
        else
        {
            // Executes if list is having elements
            // Link part of the node which is pointed by temp variable
            temp->link = newnode;
            // temp is pointing to newnode
            temp = newnode;
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void linkedlist::display()
{
    temp = start; // pointing to start node

    if (start == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL\n";
    }
}

int main()
{

    linkedlist l;
    l.insert();
    l.display();


    return 0;
}