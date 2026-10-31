#include <iostream>
using namespace std;

int main()
{
    int a[100], n, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter value: ";
    cin >> value;

    if(pos < 1 || pos > n+1 || n >= 100)
    {
        cout << "Invalid position or array full";
        return 0;
    }

    for(int i = n; i >= pos; i--)
        a[i] = a[i-1];

    a[pos-1] = value;
    n++;

    cout << "Array after insertion: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}