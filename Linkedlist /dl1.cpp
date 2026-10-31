#include <iostream>
using namespace std;

struct Node { int data; Node *prev, *next; };
Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node{x, NULL, head};
    if (head) head->prev = n;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL, NULL};
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void deleteValue(int x) {
    Node* t = head;
    while (t && t->data != x) t = t->next;
    if (!t) { cout << "Not found\n"; return; }
    if (t->prev) t->prev->next = t->next; else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

void displayForward() {
    for (Node* t = head; t; t = t->next) cout << t->data << " <-> ";
    cout << "NULL\n";
}

void displayBackward() {
    if (!head) { cout << "List empty\n"; return; }
    Node* t = head;
    while (t->next) t = t->next;
    for (; t; t = t->prev) cout << t->data << " <-> ";
    cout << "NULL\n";
}

int main() {
    int ch, x;
    do {
        cout << "\n1.Insert Begin 2.Insert End 3.Delete 4.Display Forward 5.Display Backward 6.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> x; insertBegin(x); break;
            case 2: cout << "Value: "; cin >> x; insertEnd(x); break;
            case 3: cout << "Value to delete: "; cin >> x; deleteValue(x); break;
            case 4: displayForward(); break;
            case 5: displayBackward(); break;
        }
    } while (ch != 6);
    return 0;
}