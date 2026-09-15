#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    string isbn;
    int year{};
    bool borrowed{};
};

void addBook(Book books[], int &count) {
    if (count >= MAX_BOOKS) {
        cout << "Library is full.\n";
        return;
    }
    Book b;
    cout << "Title: "; getline(cin >> ws, b.title);
    cout << "Author: "; getline(cin, b.author);
    cout << "ISBN: "; getline(cin, b.isbn);
    cout << "Year: "; cin >> b.year;
    b.borrowed = false;
    books[count++] = b;
    cout << "Book added.\n";
}

int findByISBN(const Book books[], int count, const string &isbn) {
    for (int i = 0; i < count; ++i)
        if (books[i].isbn == isbn) return i;
    return -1;
}

void printBook(const Book &book) {
    cout << book.title << " by " << book.author
         << " (" << book.year << ") - "
         << (book.borrowed ? "Borrowed" : "Available") << '\n';
}

void searchBook(const Book books[], int count) {
    int choice;
    cout << "Search by: 1. Title  2. ISBN\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        string title;
        cout << "Enter title: "; getline(cin >> ws, title);
        for (int i = 0; i < count; ++i) {
            if (books[i].title == title) {
                printBook(books[i]);
                return;
            }
        }
        cout << "Book not found.\n";
    } else if (choice == 2) {
        string isbn;
        cout << "Enter ISBN: "; getline(cin >> ws, isbn);
        int i = findByISBN(books, count, isbn);
        if (i == -1) cout << "Book not found.\n";
        else printBook(books[i]);
    } else {
        cout << "Invalid search option.\n";
    }
}

void changeStatus(Book books[], int count, bool borrow) {
    string isbn;
    cout << "Enter ISBN: ";
    getline(cin >> ws, isbn);
    int i = findByISBN(books, count, isbn);
    if (i == -1) {
        cout << "Book not found.\n";
        return;
    }

    if (borrow && books[i].borrowed) cout << "Book is already borrowed.\n";
    else if (!borrow && !books[i].borrowed) cout << "Book is already available.\n";
    else {
        books[i].borrowed = borrow;
        cout << (borrow ? "Book borrowed.\n" : "Book returned.\n");
    }
}

void displayAll(const Book books[], int count) {
    cout << left << setw(25) << "Title" << setw(20) << "Author"
         << setw(18) << "ISBN" << setw(8) << "Year" << "Status\n";
    for (int i = 0; i < count; ++i)
        cout << setw(25) << books[i].title << setw(20) << books[i].author
             << setw(18) << books[i].isbn << setw(8) << books[i].year
             << (books[i].borrowed ? "Borrowed" : "Available") << '\n';
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0, choice;
    do {
        cout << "\n--- Library Book Management ---\n"
             << "1. Add book\n2. Search book\n3. Borrow book\n4. Return book\n"
             << "5. Display all\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(books, count); break;
            case 2: searchBook(books, count); break;
            case 3: changeStatus(books, count, true); break;
            case 4: changeStatus(books, count, false); break;
            case 5: displayAll(books, count); break;
            case 6: cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
