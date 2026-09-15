#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_PATIENTS = 100;

struct Patient {
    int id{};
    string name;
    int age{};
    string disease;
};

void addPatient(Patient patients[], int &count) {
    if (count >= MAX_PATIENTS) {
        cout << "Patient list is full.\n";
        return;
    }
    Patient p;
    cout << "Patient ID: "; cin >> p.id;
    cout << "Name: "; getline(cin >> ws, p.name);
    cout << "Age: "; cin >> p.age;
    cout << "Disease: "; getline(cin >> ws, p.disease);

    if (p.age < 0) {
        cout << "Invalid age.\n";
        return;
    }
    patients[count++] = p;
    cout << "Patient added.\n";
}

void printPatient(const Patient &p) {
    cout << "ID: " << p.id
         << "\nName: " << p.name
         << "\nAge: " << p.age
         << "\nDisease: " << p.disease << '\n';
}

void searchPatient(const Patient patients[], int count) {
    int choice;
    cout << "Search by: 1. ID  2. Name\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter patient ID: "; cin >> id;
        for (int i = 0; i < count; ++i) {
            if (patients[i].id == id) {
                printPatient(patients[i]);
                return;
            }
        }
    } else if (choice == 2) {
        string name;
        cout << "Enter patient name: "; getline(cin >> ws, name);
        for (int i = 0; i < count; ++i) {
            if (patients[i].name == name) {
                printPatient(patients[i]);
                return;
            }
        }
    } else {
        cout << "Invalid search option.\n";
        return;
    }
    cout << "Patient not found.\n";
}

void displayAll(const Patient patients[], int count) {
    cout << left << setw(10) << "ID" << setw(25) << "Name"
         << setw(8) << "Age" << "Disease\n";
    for (int i = 0; i < count; ++i)
        cout << setw(10) << patients[i].id << setw(25) << patients[i].name
             << setw(8) << patients[i].age << patients[i].disease << '\n';
}

int main() {
    Patient patients[MAX_PATIENTS];
    int count = 0, choice;

    do {
        cout << "\n--- Hospital Patient Records ---\n"
             << "1. Add patient\n2. Search patient\n3. Display all\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addPatient(patients, count); break;
            case 2: searchPatient(patients, count); break;
            case 3: displayAll(patients, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
