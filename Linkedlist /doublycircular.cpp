#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void insert()
{
    int value;
    cout << "Enter value: ";
    cin >> value;

    Node *newnode = new Node;
    newnode->data = value;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        Node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
    }
}

void deleteNode()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    if(head->next == head)
    {
        head = NULL;
    }
    else
    {
        Node *last = head->prev;

        head = head->next;
        head->prev = last;
        last->next = head;
    }

    delete temp;
}

void display()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }
    }
    while(choice != 4);

    return 0;
}