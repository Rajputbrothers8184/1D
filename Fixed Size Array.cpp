#include <iostream>
using namespace std;
int main() {
    const int SIZE = 5; // Fixed size of the array
    int array[SIZE];
    cout << "Enter " << SIZE << " elements for the array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "The array is: ";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
