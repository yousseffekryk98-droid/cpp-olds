#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_BOOKINGS = 100;
const double PRICE_PER_NIGHT = 1200.0;

struct Booking {
    string guestName;
    int roomNumber{};
    int nights{};
};

double totalCost(const Booking &b) {
    return b.nights * PRICE_PER_NIGHT;
}

void addBooking(Booking bookings[], int &count) {
    if (count >= MAX_BOOKINGS) return;
    Booking b;
    cout << "Guest name: "; getline(cin >> ws, b.guestName);
    cout << "Room number: "; cin >> b.roomNumber;
    cout << "Number of nights: "; cin >> b.nights;
    if (b.roomNumber <= 0 || b.nights <= 0) {
        cout << "Invalid room number or number of nights.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        if (bookings[i].roomNumber == b.roomNumber) {
            cout << "Room is already reserved.\n";
            return;
        }
    }
    bookings[count++] = b;
    cout << "Reservation added. Total: " << totalCost(b) << '\n';
}

void searchBooking(const Booking bookings[], int count) {
    int room;
    cout << "Room number: "; cin >> room;
    for (int i = 0; i < count; ++i) {
        if (bookings[i].roomNumber == room) {
            cout << bookings[i].guestName << " | " << bookings[i].nights
                 << " night(s) | Total: " << totalCost(bookings[i]) << '\n';
            return;
        }
    }
    cout << "Reservation not found.\n";
}

void displayAll(const Booking bookings[], int count) {
    cout << left << setw(10) << "Room" << setw(25) << "Guest"
         << setw(10) << "Nights" << "Total\n";
    for (int i = 0; i < count; ++i)
        cout << setw(10) << bookings[i].roomNumber << setw(25) << bookings[i].guestName
             << setw(10) << bookings[i].nights << totalCost(bookings[i]) << '\n';
}

int main() {
    Booking bookings[MAX_BOOKINGS];
    int count = 0, choice;
    do {
        cout << "\n--- Hotel Reservation System ---\n"
             << "1. Add reservation\n2. Search by room\n3. Display all\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBooking(bookings, count); break;
            case 2: searchBooking(bookings, count); break;
            case 3: displayAll(bookings, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
