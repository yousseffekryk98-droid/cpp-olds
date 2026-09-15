#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_CARS = 100;

struct Car {
    int id{};
    string model;
    double dailyPrice{};
    bool rented{};
    string customer;
    int rentalDays{};
};

int findCar(const Car cars[], int count, int id) {
    for (int i = 0; i < count; ++i)
        if (cars[i].id == id) return i;
    return -1;
}

void addCar(Car cars[], int &count) {
    if (count >= MAX_CARS) return;
    Car c;
    cout << "Car ID: "; cin >> c.id;
    if (findCar(cars, count, c.id) != -1) {
        cout << "Car ID already exists.\n";
        return;
    }
    cout << "Model: "; getline(cin >> ws, c.model);
    cout << "Daily price: "; cin >> c.dailyPrice;
    if (c.dailyPrice < 0) {
        cout << "Invalid price.\n";
        return;
    }
    c.rented = false;
    cars[count++] = c;
}

void rentCar(Car cars[], int count) {
    int id;
    cout << "Car ID: "; cin >> id;
    int i = findCar(cars, count, id);
    if (i == -1) {
        cout << "Car not found.\n";
        return;
    }
    if (cars[i].rented) {
        cout << "Car is already rented.\n";
        return;
    }
    cout << "Customer name: "; getline(cin >> ws, cars[i].customer);
    cout << "Number of days: "; cin >> cars[i].rentalDays;
    if (cars[i].rentalDays <= 0) {
        cout << "Invalid rental duration.\n";
        cars[i].rentalDays = 0;
        cars[i].customer.clear();
        return;
    }
    cars[i].rented = true;
    cout << "Total rental cost: " << cars[i].dailyPrice * cars[i].rentalDays << '\n';
}

void displayCars(const Car cars[], int count) {
    cout << left << setw(8) << "ID" << setw(25) << "Model"
         << setw(12) << "Daily" << setw(12) << "Status" << "Customer / Total\n";
    for (int i = 0; i < count; ++i) {
        cout << setw(8) << cars[i].id << setw(25) << cars[i].model
             << setw(12) << cars[i].dailyPrice << setw(12)
             << (cars[i].rented ? "Rented" : "Available");
        if (cars[i].rented)
            cout << cars[i].customer << " / " << cars[i].dailyPrice * cars[i].rentalDays;
        cout << '\n';
    }
}

int main() {
    Car cars[MAX_CARS];
    int count = 0, choice;
    do {
        cout << "\n--- Car Rental Management ---\n"
             << "1. Add car\n2. Rent car\n3. Display cars\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addCar(cars, count); break;
            case 2: rentCar(cars, count); break;
            case 3: displayCars(cars, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
