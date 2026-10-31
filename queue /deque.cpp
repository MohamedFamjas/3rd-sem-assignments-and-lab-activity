#include <iostream>
using namespace std;

#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

void insertFront()
{
    int value;

    if((rear+1)%SIZE == front)
    {
        cout << "Deque is full\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    if(front == -1)
        front = rear = 0;
    else
        front = (front-1+SIZE)%SIZE;

    dq[front] = value;
}

void insertRear()
{
    int value;

    if((rear+1)%SIZE == front)
    {
        cout << "Deque is full\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    if(front == -1)
        front = rear = 0;
    else
        rear = (rear+1)%SIZE;

    dq[rear] = value;
}

void deleteFront()
{
    if(front == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deleted: " << dq[front] << endl;

    if(front == rear)
        front = rear = -1;
    else
        front = (front+1)%SIZE;
}

void deleteRear()
{
    if(front == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    cout << "Deleted: " << dq[rear] << endl;

    if(front == rear)
        front = rear = -1;
    else
        rear = (rear-1+SIZE)%SIZE;
}

void display()
{
    if(front == -1)
    {
        cout << "Deque is empty\n";
        return;
    }

    int i = front;

    while(true)
    {
        cout << dq[i] << " ";

        if(i == rear)
            break;

        i = (i+1)%SIZE;
    }

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1.Insert Front";
        cout << "\n2.Insert Rear";
        cout << "\n3.Delete Front";
        cout << "\n4.Delete Rear";
        cout << "\n5.Display";
        cout << "\n6.Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while(choice != 6);

    return 0;
}