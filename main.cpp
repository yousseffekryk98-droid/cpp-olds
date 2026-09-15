#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    double monthlyIncome{};
    double loanAmount{};
    int creditScore{};
};

bool isEligible(const Customer &c, string &reason) {
    if (c.monthlyIncome < 10000) {
        reason = "Monthly income is below the required threshold.";
        return false;
    }
    if (c.creditScore < 650) {
        reason = "Credit score is below the required level.";
        return false;
    }
    if (c.loanAmount > c.monthlyIncome * 24) {
        reason = "Requested loan is too high compared with income.";
        return false;
    }
    reason = "Income, credit score, and requested amount meet the requirements.";
    return true;
}

Customer collectCustomer() {
    Customer c;
    cout << "Customer name: "; getline(cin >> ws, c.name);
    cout << "Monthly income: "; cin >> c.monthlyIncome;
    cout << "Requested loan amount: "; cin >> c.loanAmount;
    cout << "Credit score: "; cin >> c.creditScore;
    return c;
}

int main() {
    int choice;
    do {
        cout << "\n--- Bank Loan Eligibility Checker ---\n"
             << "1. Check customer\n2. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Customer c = collectCustomer();
            if (c.monthlyIncome < 0 || c.loanAmount <= 0 || c.creditScore < 0) {
                cout << "Invalid customer data.\n";
                continue;
            }

            string reason;
            bool approved = isEligible(c, reason);
            cout << "\nCustomer: " << c.name
                 << "\nStatus: " << (approved ? "APPROVED" : "REJECTED")
                 << "\nExplanation: " << reason << '\n';
        } else if (choice != 2) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 2);

    return 0;
}
