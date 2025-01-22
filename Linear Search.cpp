#include <iostream>
using namespace std;
int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;
    int array[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "Enter the element to search: ";
    cin >> target;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (array[i] == target) {
            cout << "Element " << target << " found at position " << i + 1 << " (index " << i << ").\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element " << target << " not found in the array.\n";
    }
    return 0;
}
