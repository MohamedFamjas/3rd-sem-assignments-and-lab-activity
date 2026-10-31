#include <iostream>
using namespace std;

int a[100], n = 0;

void display() {
    if (n == 0) { cout << "Array is empty\n"; return; }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void insertAt(int pos, int x) {          // pos is 1-based
    if (pos < 1 || pos > n + 1) { cout << "Invalid position\n"; return; }
    for (int i = n; i >= pos; i--) a[i] = a[i - 1];
    a[pos - 1] = x;
    n++;
}

void deleteAt(int pos) {
    if (pos < 1 || pos > n) { cout << "Invalid position\n"; return; }
    for (int i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

void update(int pos, int x) {
    if (pos < 1 || pos > n) { cout << "Invalid position\n"; return; }
    a[pos - 1] = x;
}

int main() {
    int ch, x, pos;
    do {
        cout << "\n1.Insert 2.Delete 3.Update 4.Display 5.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Position and value: "; cin >> pos >> x; insertAt(pos, x); break;
            case 2: cout << "Position: "; cin >> pos; deleteAt(pos); break;
            case 3: cout << "Position and new value: "; cin >> pos >> x; update(pos, x); break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}