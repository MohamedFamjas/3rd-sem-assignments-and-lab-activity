#include <iostream>
using namespace std;

struct Node { int data; Node *prev, *next; };

void insertEnd(Node*& head, int x) {
    Node* n = new Node{x, NULL, NULL};
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

Node* secondLast(Node* head) {
    if (!head || !head->next) return NULL;       // fewer than 2 nodes
    Node* t = head;
    while (t->next) t = t->next;                 // go to last node
    return t->prev;                              // the node before it
}

int main() {
    Node* head = NULL;
    int n, x;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    Node* r = secondLast(head);
    if (r) cout << "Second last node: " << r->data << " (address " << r << ")\n";
    else cout << "List has fewer than 2 nodes\n";
    return 0;
}