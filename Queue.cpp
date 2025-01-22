#include <iostream>
using namespace std;

class Queue {
private:
    int front;    // Points to the front of the queue
    int rear;     // Points to the rear of the queue
    int maxSize;  // Maximum size of the queue
    int queue[100]; // Array to hold the queue elements

public:
    // Constructor to initialize the queue
    Queue(int size) {
        front = -1;
        rear = -1;
        maxSize = size;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (rear == maxSize - 1) {
            cout << "Queue overflow! Cannot enqueue " << value << ".\n";
            return;
        }
        if (front == -1) front = 0; // Set front to 0 if queue was empty
        queue[++rear] = value;
        cout << value << " added to the queue.\n";
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow! No elements to dequeue.\n";
            return;
        }
        cout << queue[front++] << " removed from the queue.\n";
        if (front > rear) {
            front = -1; // Reset the queue when it becomes empty
            rear = -1;
        }
    }

    // Function to display the queue elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    // Input the maximum size of the queue
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size); // Create a queue with the given size

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
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
