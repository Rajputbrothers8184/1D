#include <iostream>
using namespace std;
struct Student {
    int rollNumber;
    string name;
    float marks;
};
int main() {
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Marks: ";
    cin >> student.marks;
    cout << "\nStudent Details:\n";
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Name: " << student.name << endl;
    cout << "Marks: " << student.marks << endl;
    return 0;
}
