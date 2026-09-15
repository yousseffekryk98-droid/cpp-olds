#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ITEMS = 5;

struct MenuItem {
    string name;
    double price{};
};

void displayMenu(const MenuItem menu[]) {
    cout << left << setw(6) << "No." << setw(25) << "Item" << "Price\n";
    for (int i = 0; i < ITEMS; ++i)
        cout << setw(6) << i + 1 << setw(25) << menu[i].name
             << fixed << setprecision(2) << menu[i].price << '\n';
}

void orderItem(const MenuItem menu[], int quantities[]) {
    displayMenu(menu);
    int item, quantity;
    cout << "Item number: "; cin >> item;
    cout << "Quantity: "; cin >> quantity;

    if (item < 1 || item > ITEMS || quantity <= 0) {
        cout << "Invalid order.\n";
        return;
    }

    quantities[item - 1] += quantity;
    cout << "Item added to order.\n";
}

double calculateBill(const MenuItem menu[], const int quantities[]) {
    double total = 0;
    for (int i = 0; i < ITEMS; ++i)
        total += menu[i].price * quantities[i];
    return total;
}

void viewBill(const MenuItem menu[], const int quantities[]) {
    cout << "\n--- Current Bill ---\n";
    bool hasItems = false;
    for (int i = 0; i < ITEMS; ++i) {
        if (quantities[i] > 0) {
            hasItems = true;
            cout << menu[i].name << " x " << quantities[i]
                 << " = " << menu[i].price * quantities[i] << '\n';
        }
    }
    if (!hasItems) cout << "No items ordered.\n";
    cout << "Total = " << fixed << setprecision(2)
         << calculateBill(menu, quantities) << '\n';
}

int main() {
    MenuItem menu[ITEMS] = {
        {"Chicken Burger", 120},
        {"Beef Burger", 145},
        {"Pizza", 180},
        {"French Fries", 60},
        {"Soft Drink", 35}
    };

    int quantities[ITEMS] = {};
    int choice;

    do {
        cout << "\n--- Restaurant Ordering System ---\n"
             << "1. View menu\n2. Order item\n3. View bill\n4. Confirm order\n5. Cancel order\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayMenu(menu); break;
            case 2: orderItem(menu, quantities); break;
            case 3: viewBill(menu, quantities); break;
            case 4:
                viewBill(menu, quantities);
                cout << "Order confirmed.\n";
                for (int &q : quantities) q = 0;
                break;
            case 5:
                for (int &q : quantities) q = 0;
                cout << "Order cancelled.\n";
                break;
            case 6: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
