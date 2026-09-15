#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id{};
    string name;
    char attendance{'N'};
};

void addStudents(Student students[], int &count) {
    cout << "How many students? ";
    cin >> count;
    if (count < 1) count = 0;
    if (count > MAX_STUDENTS) count = MAX_STUDENTS;

    for (int i = 0; i < count; ++i) {
        cout << "\nStudent " << i + 1 << " ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        getline(cin >> ws, students[i].name);
    }
}

void markAttendance(Student students[], int count) {
    for (int i = 0; i < count; ++i) {
        char status;
        do {
            cout << students[i].name << " (P/A): ";
            cin >> status;
            status = static_cast<char>(toupper(status));
        } while (status != 'P' && status != 'A');
        students[i].attendance = status;
    }
}

void report(const Student students[], int count) {
    if (count == 0) {
        cout << "No students loaded.\n";
        return;
    }

    int present = 0;
    cout << left << setw(10) << "ID" << setw(25) << "Name" << "Status\n";
    for (int i = 0; i < count; ++i) {
        if (students[i].attendance == 'P') ++present;
        cout << setw(10) << students[i].id << setw(25) << students[i].name
             << (students[i].attendance == 'P' ? "Present" :
                 students[i].attendance == 'A' ? "Absent" : "Not marked") << '\n';
    }

    double percentage = 100.0 * present / count;
    cout << fixed << setprecision(2)
         << "Present: " << present << '/' << count
         << " (" << percentage << "%)\n";
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    do {
        cout << "\n--- School Attendance System ---\n"
             << "1. Enter class list\n2. Mark attendance\n3. Show report\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudents(students, count); break;
            case 2: markAttendance(students, count); break;
            case 3: report(students, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
