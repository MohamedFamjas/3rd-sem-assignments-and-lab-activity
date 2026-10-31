#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int binarySearch(int a[], int n, int key) {   // array must be sorted
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int a[50], n, key;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Linear search - enter key: ";
    cin >> key;
    int r = linearSearch(a, n, key);
    if (r == -1) cout << "Not found\n"; else cout << "Found at index " << r << endl;

    bubbleSort(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    cout << "\nBinary search - enter key: ";
    cin >> key;
    r = binarySearch(a, n, key);
    if (r == -1) cout << "Not found\n"; else cout << "Found at index " << r << endl;
    return 0;
}