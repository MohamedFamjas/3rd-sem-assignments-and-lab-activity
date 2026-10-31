#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push()
{
    int value;

    if(top == SIZE-1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        top++;
        stack[top] = value;

        cout << "Element inserted\n";
    }
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        cout << "Deleted element: " << stack[top] << endl;
        top--;
    }
}

void peek()
{
    if(top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << stack[top] << endl;
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack elements: ";

        for(int i = top; i >= 0; i--)
            cout << stack[i] << " ";

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