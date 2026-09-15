#include <iostream>
#include <iomanip>
using namespace std;

void checkBalance(const double *balance) {
    cout << fixed << setprecision(2) << "Current balance: " << *balance << '\n';
}

void deposit(double *balance) {
    double amount;
    cout << "Deposit amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }
    *balance += amount;
    cout << "Deposit successful.\n";
}

void withdraw(double *balance) {
    double amount;
    cout << "Withdrawal amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
    } else if (amount > *balance) {
        cout << "Insufficient balance.\n";
    } else {
        *balance -= amount;
        cout << "Withdrawal successful.\n";
    }
}

int main() {
    const int savedPin = 1234;
    int pin, attempts = 0;

    while (attempts < 3) {
        cout << "Enter PIN: ";
        cin >> pin;
        if (pin == savedPin) break;
        cout << "Incorrect PIN.\n";
        ++attempts;
    }

    if (attempts == 3) {
        cout << "Too many failed attempts.\n";
        return 0;
    }

    double balance = 1000.0;
    int choice;

    do {
        cout << "\n--- ATM Menu ---\n"
             << "1. Check balance\n2. Deposit\n3. Withdraw\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: checkBalance(&balance); break;
            case 2: deposit(&balance); break;
            case 3: withdraw(&balance); break;
            case 4: cout << "Thank you for using the ATM.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
