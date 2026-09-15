#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account {
    string customerName;
    int number{};
    string type;
    double balance{};
};

int findAccount(const Account accounts[], int count, int number) {
    for (int i = 0; i < count; ++i)
        if (accounts[i].number == number) return i;
    return -1;
}

void addAccount(Account accounts[], int &count) {
    if (count >= MAX_ACCOUNTS) return;
    Account a;
    cout << "Customer name: "; getline(cin >> ws, a.customerName);
    cout << "Account number: "; cin >> a.number;
    if (findAccount(accounts, count, a.number) != -1) {
        cout << "Account number already exists.\n";
        return;
    }
    cout << "Account type: "; getline(cin >> ws, a.type);
    cout << "Opening balance: "; cin >> a.balance;
    if (a.balance < 0) {
        cout << "Balance cannot be negative.\n";
        return;
    }
    accounts[count++] = a;
    cout << "Account created.\n";
}

void transaction(Account accounts[], int count, bool deposit) {
    int number;
    double amount;
    cout << "Account number: "; cin >> number;
    int i = findAccount(accounts, count, number);
    if (i == -1) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Amount: "; cin >> amount;
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
    } else if (!deposit && amount > accounts[i].balance) {
        cout << "Insufficient balance.\n";
    } else {
        accounts[i].balance += deposit ? amount : -amount;
        cout << "Transaction successful. New balance: " << accounts[i].balance << '\n';
    }
}

void searchAccount(const Account accounts[], int count) {
    int number;
    cout << "Account number: "; cin >> number;
    int i = findAccount(accounts, count, number);
    if (i == -1) cout << "Account not found.\n";
    else cout << accounts[i].customerName << " | " << accounts[i].type
              << " | Balance: " << accounts[i].balance << '\n';
}

void displayAll(const Account accounts[], int count) {
    cout << left << setw(10) << "Number" << setw(25) << "Customer"
         << setw(15) << "Type" << "Balance\n";
    for (int i = 0; i < count; ++i)
        cout << setw(10) << accounts[i].number << setw(25) << accounts[i].customerName
             << setw(15) << accounts[i].type << fixed << setprecision(2)
             << accounts[i].balance << '\n';
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = 0, choice;
    do {
        cout << "\n--- Bank Account Management ---\n"
             << "1. Add account\n2. Deposit\n3. Withdraw\n4. Search\n5. Display all\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addAccount(accounts, count); break;
            case 2: transaction(accounts, count, true); break;
            case 3: transaction(accounts, count, false); break;
            case 4: searchAccount(accounts, count); break;
            case 5: displayAll(accounts, count); break;
            case 6: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
