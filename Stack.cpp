#include <iostream>
using namespace std;

class Stack {
private:
    int top;              // Points to the top of the stack
    int stack[100];       // Array to hold stack elements
    int maxSize;          // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        top = -1;         // Stack is initially empty
        maxSize = size;   // Set the maximum size
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == maxSize - 1) {
            cout << "Stack overflow! Cannot push " << value << ".\n";
            return;
        }
        stack[++top] = value;
        cout << value << " pushed onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack underflow! No elements to pop.\n";
            return;
        }
        cout << stack[top--] << " popped from the stack.\n";
    }

    // Function to display the stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    // Input the maximum size of the stack
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size); // Create a stack with the given size

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
