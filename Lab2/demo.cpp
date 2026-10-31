#include "array.cpp"

int main()
{
    array<int> arr;
    int choice, l, u;
    char ch;

    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Quick Sort (Lomuto)" << endl;
        cout << "7. Display Array" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter lower bound: "; cin >> l;
                cout << "Enter upper bound: "; cin >> u;
                arr.setLB(l);
                arr.setUB(u);
                arr.create();
                break;
            case 2: arr.bubbleSort(); cout << "Sorted using Bubble Sort\n"; break;
            case 3: arr.insertionSort(); cout << "Sorted using Insertion Sort\n"; break;
            case 4: arr.selectionSort(); cout << "Sorted using Selection Sort\n"; break;
            case 5: arr.mergeSort(); cout << "Sorted using Merge Sort\n"; break;
            case 6: arr.quickSort(); cout << "Sorted using Quick Sort\n"; break;
            case 7: arr.display(); break;
            default: cout << "Invalid choice!\n";
        }

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}