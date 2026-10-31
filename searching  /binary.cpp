#include <iostream>
using namespace std;

int main()
{
    int a[100], n, key;
    int low, high, mid;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter search element: ";
    cin >> key;

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            cout << "Element found at position " << mid+1;
            return 0;
        }
        else if(a[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }

    cout << "Element not found";

    return 0;
}