#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node{x, head};
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL};
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void insertPos(int x, int pos) {
    if (pos == 1) { insertBegin(x); return; }
    Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t) { cout << "Invalid position\n"; return; }
    t->next = new Node{x, t->next};
}

void deleteValue(int x) {
    if (!head) { cout << "List empty\n"; return; }
    if (head->data == x) { Node* d = head; head = head->next; delete d; return; }
    Node* t = head;
    while (t->next && t->next->data != x) t = t->next;
    if (!t->next) { cout << "Not found\n"; return; }
    Node* d = t->next;
    t->next = d->next;
    delete d;
}

void search(int x) {
    int pos = 1;
    for (Node* t = head; t; t = t->next, pos++)
        if (t->data == x) { cout << "Found at position " << pos << endl; return; }
    cout << "Not found\n";
}

void display() {
    if (!head) { cout << "List empty\n"; return; }
    for (Node* t = head; t; t = t->next) cout << t->data << " -> ";
    cout << "NULL\n";
}

int main() {
    int ch, x, pos;
    do {
        cout << "\n1.Insert Begin 2.Insert End 3.Insert at Position 4.Delete 5.Search 6.Display 7.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> x; insertBegin(x); break;
            case 2: cout << "Value: "; cin >> x; insertEnd(x); break;
            case 3: cout << "Value and position: "; cin >> x >> pos; insertPos(x, pos); break;
            case 4: cout << "Value to delete: "; cin >> x; deleteValue(x); break;
            case 5: cout << "Value to search: "; cin >> x; search(x); break;
            case 6: display(); break;
        }
    } while (ch != 7);
    return 0;
}