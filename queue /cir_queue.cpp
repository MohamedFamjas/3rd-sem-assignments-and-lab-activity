#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if((rear+1)%SIZE == front)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        if(front == -1)
            front = rear = 0;
        else
            rear = (rear+1)%SIZE;

        queue[rear] = value;

        cout << "Element inserted\n";
    }
}

void dequeue()
{
    if(front == -1)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted element: " << queue[front] << endl;

        if(front == rear)
            front = rear = -1;
        else
            front = (front+1)%SIZE;
    }
}

void display()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        int i = front;

        while(true)
        {
            cout << queue[i] << " ";

            if(i == rear)
                break;

            i = (i+1)%SIZE;
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