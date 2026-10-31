#include <iostream>
using namespace std;

struct Node
{
    int data;
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
    }
    else
    {
        Node *temp = head;

        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
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
        delete head;
        head = NULL;
    }
    else
    {
        Node *last = head;

        while(last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;

        delete temp;
    }
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