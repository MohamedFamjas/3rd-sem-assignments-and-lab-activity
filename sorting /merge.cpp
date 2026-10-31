#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int b[100];
    int i = low, j = mid+1, k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= high)
        b[k++] = a[j++];

    for(int i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}