#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
const int SUBJECTS = 5;

struct Student {
    string name;
    int id{};
    double marks[SUBJECTS]{};
    double total{};
    double average{};
    bool passed{};
};

void calculateResult(Student &s) {
    s.total = 0;
    for (double mark : s.marks) s.total += mark;
    s.average = s.total / SUBJECTS;
    s.passed = s.average >= 50.0;
}

void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Student list is full.\n";
        return;
    }

    Student s;
    cout << "Student name: ";
    getline(cin >> ws, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    for (int i = 0; i < SUBJECTS; ++i) {
        do {
            cout << "Mark for subject " << i + 1 << " (0-100): ";
            cin >> s.marks[i];
        } while (s.marks[i] < 0 || s.marks[i] > 100);
    }

    calculateResult(s);
    students[count++] = s;
    cout << "Student added successfully.\n";
}

void displayStudent(const Student &s) {
    cout << left << setw(20) << s.name
         << setw(10) << s.id
         << setw(10) << fixed << setprecision(2) << s.total
         << setw(10) << s.average
         << (s.passed ? "PASS" : "FAIL") << '\n';
}

void searchStudent(const Student students[], int count) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << left << setw(20) << "Name" << setw(10) << "ID"
                 << setw(10) << "Total" << setw(10) << "Average" << "Result\n";
            displayStudent(students[i]);
            cout << "Marks: ";
            for (double mark : students[i].marks) cout << mark << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "Student not found.\n";
}

void displayAll(const Student students[], int count) {
    if (count == 0) {
        cout << "No student records.\n";
        return;
    }
    cout << left << setw(20) << "Name" << setw(10) << "ID"
         << setw(10) << "Total" << setw(10) << "Average" << "Result\n";
    for (int i = 0; i < count; ++i) displayStudent(students[i]);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    do {
        cout << "\n--- Student Grade Management ---\n"
             << "1. Add student\n2. Search by ID\n3. Display all results\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students, count); break;
            case 2: searchStudent(students, count); break;
            case 3: displayAll(students, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
