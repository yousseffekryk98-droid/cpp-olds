#include <iostream>
#include <string>
using namespace std;

const int MAX_CANDIDATES = 10;

struct Candidate {
    string name;
    int votes{};
};

void addCandidates(Candidate candidates[], int &count) {
    cout << "Number of candidates (1-10): ";
    cin >> count;
    if (count < 1) count = 1;
    if (count > MAX_CANDIDATES) count = MAX_CANDIDATES;

    for (int i = 0; i < count; ++i) {
        cout << "Candidate " << i + 1 << " name: ";
        getline(cin >> ws, candidates[i].name);
        candidates[i].votes = 0;
    }
}

void vote(Candidate candidates[], int count) {
    if (count == 0) {
        cout << "Add candidates first.\n";
        return;
    }
    for (int i = 0; i < count; ++i)
        cout << i + 1 << ". " << candidates[i].name << '\n';

    int choice;
    cout << "Vote for candidate number: ";
    cin >> choice;
    if (choice < 1 || choice > count) cout << "Invalid candidate.\n";
    else {
        ++candidates[choice - 1].votes;
        cout << "Vote recorded.\n";
    }
}

void showResults(const Candidate candidates[], int count) {
    for (int i = 0; i < count; ++i)
        cout << candidates[i].name << ": " << candidates[i].votes << " vote(s)\n";
}

void declareWinner(const Candidate candidates[], int count) {
    if (count == 0) {
        cout << "No candidates.\n";
        return;
    }
    int maxVotes = candidates[0].votes;
    for (int i = 1; i < count; ++i)
        if (candidates[i].votes > maxVotes) maxVotes = candidates[i].votes;

    int winners = 0;
    for (int i = 0; i < count; ++i)
        if (candidates[i].votes == maxVotes) ++winners;

    if (winners > 1) {
        cout << "There is a tie between:\n";
        for (int i = 0; i < count; ++i)
            if (candidates[i].votes == maxVotes)
                cout << "- " << candidates[i].name << '\n';
    } else {
        for (int i = 0; i < count; ++i)
            if (candidates[i].votes == maxVotes)
                cout << "Winner: " << candidates[i].name
                     << " with " << maxVotes << " vote(s).\n";
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int count = 0;
    addCandidates(candidates, count);

    int choice;
    do {
        cout << "\n--- Simple Voting System ---\n"
             << "1. Vote\n2. Show results\n3. Declare winner\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: vote(candidates, count); break;
            case 2: showResults(candidates, count); break;
            case 3: declareWinner(candidates, count); break;
            case 4: cout << "Voting ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
