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

// Two-pointer method: move 'fast' k nodes ahead, then move both together
Node* kthFromLast(Node* head, int k) {
    Node *fast = head, *slow = head;
    for (int i = 0; i < k; i++) {
        if (!fast) return NULL;                  // k is larger than list length
        fast = fast->next;
    }
    while (fast) { fast = fast->next; slow = slow->next; }
    return slow;
}

int main() {
    Node* head = NULL;
    int n, x, k;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    cout << "Enter k: ";
    cin >> k;
    Node* r = kthFromLast(head, k);
    if (r) cout << k << "th node from last: " << r->data << " (address " << r << ")\n";
    else cout << "Invalid k\n";
    return 0;
}