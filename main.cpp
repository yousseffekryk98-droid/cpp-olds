#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MOVIES = 3;
const int MAX_BOOKINGS = 100;

struct Movie {
    string title;
    string time;
    double price{};
};

struct Booking {
    string customer;
    int movieIndex{};
    int tickets{};
};

void displayMovies(const Movie movies[]) {
    cout << left << setw(6) << "No." << setw(25) << "Movie"
         << setw(12) << "Time" << "Price\n";
    for (int i = 0; i < MOVIES; ++i)
        cout << setw(6) << i + 1 << setw(25) << movies[i].title
             << setw(12) << movies[i].time << movies[i].price << '\n';
}

void bookTickets(const Movie movies[], Booking bookings[], int &count) {
    if (count >= MAX_BOOKINGS) return;
    displayMovies(movies);

    Booking b;
    cout << "Customer name: "; getline(cin >> ws, b.customer);
    cout << "Movie number: "; cin >> b.movieIndex;
    --b.movieIndex;
    cout << "Number of tickets: "; cin >> b.tickets;

    if (b.movieIndex < 0 || b.movieIndex >= MOVIES || b.tickets <= 0) {
        cout << "Invalid booking details.\n";
        return;
    }

    bookings[count++] = b;
    cout << "Booking confirmed. Total: "
         << movies[b.movieIndex].price * b.tickets << '\n';
}

void displayBookings(const Movie movies[], const Booking bookings[], int count) {
    cout << left << setw(22) << "Customer" << setw(25) << "Movie"
         << setw(10) << "Tickets" << "Total\n";
    for (int i = 0; i < count; ++i)
        cout << setw(22) << bookings[i].customer
             << setw(25) << movies[bookings[i].movieIndex].title
             << setw(10) << bookings[i].tickets
             << movies[bookings[i].movieIndex].price * bookings[i].tickets << '\n';
}

int main() {
    Movie movies[MOVIES] = {
        {"The Last Horizon", "15:00", 150},
        {"City Lights", "18:30", 180},
        {"Beyond Earth", "21:00", 200}
    };
    Booking bookings[MAX_BOOKINGS];
    int count = 0, choice;

    do {
        cout << "\n--- Cinema Ticket Booking ---\n"
             << "1. View movies\n2. Book tickets\n3. View bookings\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: displayMovies(movies); break;
            case 2: bookTickets(movies, bookings, count); break;
            case 3: displayBookings(movies, bookings, count); break;
            case 4: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
