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

Node* mergeSorted(Node* a, Node* b) {
    Node dummy{0, NULL};
    Node* tail = &dummy;
    while (a && b) {
        if (a->data <= b->data) { tail->next = a; a = a->next; }
        else                    { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;                      // attach the remaining nodes
    return dummy.next;
}

void display(Node* head) {
    for (Node* t = head; t; t = t->next) cout << t->data << " -> ";
    cout << "NULL\n";
}

Node* readList(const char* name) {
    Node* h = NULL;
    int n, x;
    cout << "Number of nodes in " << name << ": ";
    cin >> n;
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(h, x); }
    return h;
}

int main() {
    Node* l1 = readList("list 1");
    Node* l2 = readList("list 2");
    Node* merged = mergeSorted(l1, l2);
    cout << "Merged list: ";
    display(merged);
    return 0;
}