#include <iostream>
using namespace std;

int binarySearch(int a[], int low, int high, int key)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(a[mid] == key)
        return mid;

    else if(a[mid] < key)
        return binarySearch(a, mid+1, high, key);

    else
        return binarySearch(a, low, mid-1, key);
}

int main()
{
    int a[100], n, key, result;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter search element: ";
    cin >> key;

    result = binarySearch(a, 0, n-1, key);

    if(result == -1)
        cout << "Element not found";
    else
        cout << "Element found at position " << result+1;

    return 0;
}