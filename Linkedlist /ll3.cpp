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

Node* secondLast(Node* head) {
    if (!head || !head->next) return NULL;       // fewer than 2 nodes
    Node* t = head;
    while (t->next->next) t = t->next;
    return t;
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