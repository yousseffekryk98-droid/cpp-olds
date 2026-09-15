#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame() {
    int target = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "\nI selected a number from 1 to 100.\n";
    do {
        cout << "Your guess: ";
        cin >> guess;
        ++attempts;

        if (guess < target) cout << "Too low.\n";
        else if (guess > target) cout << "Too high.\n";
    } while (guess != target);

    cout << "Correct! You guessed it in " << attempts << " attempt(s).\n";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    char again;

    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
