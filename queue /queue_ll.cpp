#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node *newnode = new Node;

    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    cout << "Element inserted\n";
}

void dequeue()
{
    if(front == NULL)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        Node *temp = front;

        cout << "Deleted element: " << temp->data << endl;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
    }
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        Node *temp = front;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1.Enqueue";
        cout << "\n2.Dequeue";
        cout << "\n3.Display";
        cout << "\n4.Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}