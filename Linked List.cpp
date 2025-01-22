#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Node {
    int data;
    int next; // Index of the next node in the array
};

class SinglyLinkedList {
private:
    Node nodes[MAX_SIZE]; // Array to hold nodes
    int head;             // Index of the head node
    int freeIndex;        // Points to the next available space in the array

public:
    SinglyLinkedList() {
        head = -1;        // Initialize head as -1 (empty list)
        freeIndex = 0;    // First free index is 0
    }

    // Function to create a new node
    void createNode(int value) {
        if (freeIndex >= MAX_SIZE) {
            cout << "List is full. Cannot add more elements.\n";
            return;
        }
        nodes[freeIndex] = {value, -1}; // Create a new node
        if (head == -1) {
            head = freeIndex; // If the list is empty, set the new node as the head
        } else {
            int temp = head;
            while (nodes[temp].next != -1) {
                temp = nodes[temp].next;
            }
            nodes[temp].next = freeIndex; // Link the new node to the last node
        }
        freeIndex++;
    }

    // Function to insert a node at a specific position
    void insertNode(int value, int position) {
        if (freeIndex >= MAX_SIZE) {
            cout << "List is full. Cannot add more elements.\n";
            return;
        }
        if (position < 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node newNode = {value, -1};

        if (position == 0) {
            newNode.next = head;
            nodes[freeIndex] = newNode;
            head = freeIndex;
        } else {
            int temp = head, count = 0;
            while (temp != -1 && count < position - 1) {
                temp = nodes[temp].next;
                count++;
            }
            if (temp == -1) {
                cout << "Position out of range.\n";
                return;
            }
            newNode.next = nodes[temp].next;
            nodes[temp].next = freeIndex;
            nodes[freeIndex] = newNode;
        }
        freeIndex++;
    }

    // Function to delete a node at a specific position
    void deleteNode(int position) {
        if (head == -1) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (position < 0) {
            cout << "Invalid position.\n";
            return;
        }
        if (position == 0) {
            head = nodes[head].next;
        } else {
            int temp = head, count = 0;
            while (temp != -1 && count < position - 1) {
                temp = nodes[temp].next;
                count++;
            }
            if (temp == -1 || nodes[temp].next == -1) {
                cout << "Position out of range.\n";
                return;
            }
            nodes[temp].next = nodes[nodes[temp].next].next;
        }
    }

    // Function to display the list
    void displayList() {
        if (head == -1) {
            cout << "List is empty.\n";
            return;
        }
        int temp = head;
        cout << "List elements: ";
        while (temp != -1) {
            cout << nodes[temp].data << " ";
            temp = nodes[temp].next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;

    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Node\n";
        cout << "2. Insert Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to create a node: ";
            cin >> value;
            list.createNode(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            list.insertNode(value, position);
            break;
        case 3:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteNode(position);
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
