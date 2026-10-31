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

// Method 1: slow/fast pointers
Node* middleSlowFast(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Method 2 (uses the prev pointer): one pointer from the front, one from the back
Node* middleTwoEnds(Node* head) {
    if (!head) return NULL;
    Node *front = head, *back = head;
    while (back->next) back = back->next;
    while (front != back && front->next != back) {
        front = front->next;
        back = back->prev;
    }
    return back;                                 // second middle for even length
}

int main() {
    Node* head = NULL;
    int n, x;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    Node* m1 = middleSlowFast(head);
    Node* m2 = middleTwoEnds(head);
    if (m1) {
        cout << "Middle (slow/fast)  : " << m1->data << endl;
        cout << "Middle (two-pointer): " << m2->data << endl;
    } else cout << "List is empty\n";
    return 0;
}