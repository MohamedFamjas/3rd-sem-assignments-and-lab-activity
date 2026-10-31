#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node *newnode = new Node;

    newnode->data = value;
    newnode->next = top;

    top = newnode;

    cout << "Element inserted\n";
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        Node *temp = top;

        cout << "Deleted element: " << top->data << endl;

        top = top->next;

        delete temp;
    }
}

void peek()
{
    if(top == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << top->data << endl;
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        Node *temp = top;

        cout << "Stack elements: ";

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
        cout << "\n--- STACK OPERATIONS ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}