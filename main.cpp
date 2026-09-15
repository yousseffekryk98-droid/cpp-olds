#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id{};
    string name;
    string position;
    double basic{};
    double bonus{};
    double deductions{};
};

double netSalary(const Employee &e) {
    return e.basic + e.bonus - e.deductions;
}

void addEmployee(Employee employees[], int &count) {
    if (count >= MAX_EMPLOYEES) return;
    Employee e;
    cout << "Employee ID: "; cin >> e.id;
    cout << "Name: "; getline(cin >> ws, e.name);
    cout << "Position: "; getline(cin, e.position);
    cout << "Basic pay: "; cin >> e.basic;
    cout << "Bonuses: "; cin >> e.bonus;
    cout << "Deductions: "; cin >> e.deductions;
    if (e.basic < 0 || e.bonus < 0 || e.deductions < 0) {
        cout << "Payroll values cannot be negative.\n";
        return;
    }
    employees[count++] = e;
}

void searchEmployee(const Employee employees[], int count) {
    int id;
    cout << "Employee ID: "; cin >> id;
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            cout << employees[i].name << " | " << employees[i].position
                 << " | Net salary: " << netSalary(employees[i]) << '\n';
            return;
        }
    }
    cout << "Employee not found.\n";
}

void displayPayroll(const Employee employees[], int count) {
    cout << left << setw(8) << "ID" << setw(22) << "Name" << setw(18) << "Position"
         << setw(12) << "Basic" << setw(12) << "Bonus" << setw(12) << "Deduct" << "Net\n";
    for (int i = 0; i < count; ++i)
        cout << setw(8) << employees[i].id << setw(22) << employees[i].name
             << setw(18) << employees[i].position << setw(12) << employees[i].basic
             << setw(12) << employees[i].bonus << setw(12) << employees[i].deductions
             << netSalary(employees[i]) << '\n';
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0, choice;
    do {
        cout << "\n--- Employee Payroll ---\n"
             << "1. Add employee\n2. Search employee\n3. Display payroll\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: searchEmployee(employees, count); break;
            case 3: displayPayroll(employees, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
