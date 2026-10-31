#include <iostream>
using namespace std;

int main()
{
    int a[100], n, key;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter search element: ";
    cin >> key;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            cout << "Element found at position " << i+1;
            return 0;
        }
    }

    cout << "Element not found";

    return 0;
}