#include <iostream>
using namespace std;

int main()
{
    int a[100], n, pos;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter position to delete: ";
    cin >> pos;

    if(pos < 1 || pos > n)
    {
        cout << "Invalid position";
        return 0;
    }

    for(int i = pos-1; i < n-1; i++)
        a[i] = a[i+1];

    n--;

    cout << "Array after deletion: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}