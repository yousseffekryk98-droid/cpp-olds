#include <iostream>
using namespace std;

const int SEATS = 50;

void displaySeats(const int seats[]) {
    cout << "\nSeat map (0 = available, X = booked)\n";
    for (int i = 0; i < SEATS; ++i) {
        cout << "Seat " << i + 1 << ": " << (seats[i] ? "X" : "0") << '\t';
        if ((i + 1) % 5 == 0) cout << '\n';
    }
}

void bookSeat(int seats[]) {
    int seat;
    cout << "Seat number (1-50): ";
    cin >> seat;
    if (seat < 1 || seat > SEATS) cout << "Invalid seat number.\n";
    else if (seats[seat - 1]) cout << "Seat is already booked.\n";
    else {
        seats[seat - 1] = 1;
        cout << "Seat booked successfully.\n";
    }
}

void cancelSeat(int seats[]) {
    int seat;
    cout << "Seat number to cancel (1-50): ";
    cin >> seat;
    if (seat < 1 || seat > SEATS) cout << "Invalid seat number.\n";
    else if (!seats[seat - 1]) cout << "Seat is already available.\n";
    else {
        seats[seat - 1] = 0;
        cout << "Reservation cancelled.\n";
    }
}

int main() {
    int seats[SEATS] = {};
    int choice;

    do {
        cout << "\n--- Bus Reservation ---\n"
             << "1. Book seat\n2. Cancel reservation\n3. View seats\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: bookSeat(seats); break;
            case 2: cancelSeat(seats); break;
            case 3: displaySeats(seats); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
