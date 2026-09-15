#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    int id{};
    string name;
    int quantity{};
    double price{};
};

int findById(const Item items[], int count, int id) {
    for (int i = 0; i < count; ++i)
        if (items[i].id == id) return i;
    return -1;
}

void addItem(Item items[], int &count) {
    if (count >= MAX_ITEMS) {
        cout << "Inventory is full.\n";
        return;
    }
    Item item;
    cout << "Item ID: "; cin >> item.id;
    if (findById(items, count, item.id) != -1) {
        cout << "ID already exists.\n";
        return;
    }
    cout << "Item name: "; getline(cin >> ws, item.name);
    cout << "Quantity: "; cin >> item.quantity;
    cout << "Price: "; cin >> item.price;

    if (item.quantity < 0 || item.price < 0) {
        cout << "Quantity and price cannot be negative.\n";
        return;
    }

    items[count++] = item;
    cout << "Item added.\n";
}

void updateItem(Item items[], int count) {
    int id;
    cout << "Item ID: "; cin >> id;
    int index = findById(items, count, id);
    if (index == -1) {
        cout << "Item not found.\n";
        return;
    }

    cout << "New quantity: "; cin >> items[index].quantity;
    cout << "New price: "; cin >> items[index].price;
    if (items[index].quantity < 0 || items[index].price < 0) {
        cout << "Invalid values. Setting negatives to zero.\n";
        if (items[index].quantity < 0) items[index].quantity = 0;
        if (items[index].price < 0) items[index].price = 0;
    }
}

void searchItem(const Item items[], int count) {
    int choice;
    cout << "Search by: 1. ID  2. Name\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Item ID: "; cin >> id;
        int index = findById(items, count, id);
        if (index == -1) cout << "Item not found.\n";
        else cout << items[index].name << " | Qty: " << items[index].quantity
                  << " | Price: " << items[index].price << '\n';
    } else if (choice == 2) {
        string name;
        cout << "Item name: "; getline(cin >> ws, name);
        for (int i = 0; i < count; ++i) {
            if (items[i].name == name) {
                cout << "ID: " << items[i].id << " | Qty: " << items[i].quantity
                     << " | Price: " << items[i].price << '\n';
                return;
            }
        }
        cout << "Item not found.\n";
    } else {
        cout << "Invalid search option.\n";
    }
}

void displayAll(const Item items[], int count) {
    double totalValue = 0;
    cout << left << setw(8) << "ID" << setw(25) << "Name"
         << setw(10) << "Qty" << setw(12) << "Price" << "Value\n";
    for (int i = 0; i < count; ++i) {
        double value = items[i].quantity * items[i].price;
        totalValue += value;
        cout << setw(8) << items[i].id << setw(25) << items[i].name
             << setw(10) << items[i].quantity << setw(12) << fixed << setprecision(2)
             << items[i].price << value << '\n';
    }
    cout << "Total inventory value: " << totalValue << '\n';
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0, choice;

    do {
        cout << "\n--- Inventory Management ---\n"
             << "1. Add item\n2. Update item\n3. Search item\n4. List items\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addItem(items, count); break;
            case 2: updateItem(items, count); break;
            case 3: searchItem(items, count); break;
            case 4: displayAll(items, count); break;
            case 5: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
