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

// Floyd's cycle detection (slow and fast pointers)
bool hasLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = NULL;
    int n, x, pos;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    cout << "Create a loop? Enter position the last node should point to (0 for no loop): ";
    cin >> pos;
    if (pos > 0 && pos <= n) {
        Node *last = head, *target = head;
        while (last->next) last = last->next;
        for (int i = 1; i < pos; i++) target = target->next;
        last->next = target;                     // creates the loop
    }

    if (hasLoop(head)) cout << "Loop detected\n";
    else cout << "No loop\n";
    return 0;
}