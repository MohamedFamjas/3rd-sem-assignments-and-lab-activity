#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

void insertEnd(Node*& head, int x) {
    Node* n = new Node{x, NULL};
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

// New node becomes the second last node
void insertSecondLast(Node*& head, int x) {
    Node* n = new Node{x, NULL};
    if (!head) { head = n; return; }                 // empty list: only node
    if (!head->next) { n->next = head; head = n; return; }   // one node: new one goes before it
    Node* t = head;
    while (t->next->next) t = t->next;               // t = current second last
    n->next = t->next;
    t->next = n;
}

void display(Node* head) {
    for (Node* t = head; t; t = t->next) cout << t->data << " -> ";
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, x;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    cout << "Element to insert at second last: ";
    cin >> x;
    insertSecondLast(head, x);
    display(head);
    return 0;
}