#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

int main() {
    char again;
    do {
        int month, year;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;

        int days = daysInMonth(month, year);
        if (days == 0 || year <= 0) {
            cout << "Invalid month or year.\n";
        } else {
            cout << "That month has " << days << " days.\n";
            cout << year << (isLeapYear(year) ? " is" : " is not") << " a leap year.\n";
        }

        cout << "Check another date? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
