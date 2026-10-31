#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == SIZE-1)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << "Element inserted\n";
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted element: " << queue[front] << endl;

        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void peek()
{
    if(front == -1)
        cout << "Queue is empty\n";
    else
        cout << "Front element: " << queue[front] << endl;
}

void display()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        for(int i = front; i <= rear; i++)
            cout << queue[i] << " ";

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
        cout << "\n3.Peek";
        cout << "\n4.Display";
        cout << "\n5.Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}