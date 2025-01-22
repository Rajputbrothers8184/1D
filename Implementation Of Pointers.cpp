#include <iostream>
using namespace std; 

int main() {
    int num = 10;   
    int* ptr = &num;
    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value stored in ptr (Address of num): " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;
    *ptr = 20;
    cout << "\nAfter modifying value through pointer:" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    return 0;
}
