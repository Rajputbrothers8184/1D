#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];

    // Input elements of the array
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }

    // Selection Sort Logic
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Update the index of the smallest element
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    // Display the sorted array
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
