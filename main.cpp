#include <iostream>
using namespace std;

void resetBoard(char board[3][3]) {
    char value = '1';
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            board[r][c] = value++;
}

void displayBoard(const char board[3][3]) {
    cout << '\n';
    for (int r = 0; r < 3; ++r) {
        cout << " " << board[r][0] << " | " << board[r][1] << " | " << board[r][2] << '\n';
        if (r < 2) cout << "---+---+---\n";
    }
}

bool hasWon(const char board[3][3], char p) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    return (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
           (board[0][2] == p && board[1][1] == p && board[2][0] == p);
}

bool makeMove(char board[3][3], int position, char player) {
    if (position < 1 || position > 9) return false;
    int r = (position - 1) / 3;
    int c = (position - 1) % 3;
    if (board[r][c] == 'X' || board[r][c] == 'O') return false;
    board[r][c] = player;
    return true;
}

int main() {
    char again;
    do {
        char board[3][3];
        resetBoard(board);
        char player = 'X';
        bool winner = false;

        for (int moves = 0; moves < 9 && !winner; ++moves) {
            displayBoard(board);
            int position;
            cout << "Player " << player << ", choose a position (1-9): ";
            cin >> position;

            if (!makeMove(board, position, player)) {
                cout << "Invalid move. Try again.\n";
                --moves;
                continue;
            }

            winner = hasWon(board, player);
            if (!winner) player = (player == 'X') ? 'O' : 'X';
        }

        displayBoard(board);
        if (winner) cout << "Player " << player << " wins!\n";
        else cout << "The game is a draw.\n";

        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
