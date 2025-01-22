#include <iostream>
#include <algorithm> // For sort()
using namespace std;

int main() {
    int n, target;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];

    // Input elements of the array
    cout << "Enter " << n << " elements (sorted or unsorted):\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }

    // Sort the array (binary search requires a sorted array)
    sort(array, array + n);

    // Display the sorted array
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input the target element to search
    cout << "Enter the element to search: ";
    cin >> target;

    // Binary search logic
    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = low + (high - low) / 2; // Calculate the middle index

        if (array[mid] == target) {
            cout << "Element " << target << " found at position " << mid + 1 << " (index " << mid << ").\n";
            found = true;
            break;
        } else if (array[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    if (!found) {
        cout << "Element " << target << " not found in the array.\n";
    }

    return 0;
}
