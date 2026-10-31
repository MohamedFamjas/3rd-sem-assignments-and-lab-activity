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

// Slow moves 1 step, fast moves 2 steps. When fast ends, slow is at the middle.
Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node* head = NULL;
    int n, x;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    Node* m = findMiddle(head);
    if (m) cout << "Middle node: " << m->data << endl;
    else cout << "List is empty\n";
    return 0;
}