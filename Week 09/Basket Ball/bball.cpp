#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int handleScore(int);

int main() {
    vector<int> awayScores;
    vector<int> homeScores;
    bool isTie = false;
    int score;
    int totalAwayScores = 0;
    int totalHomeScores = 0;

    for (int i = 1; i < 5; i++) {
        cout << i << "Q away team score:" << endl;
        do {
            cout << "Please enter a number (0 or greater): ";
            cin >> score;
            if(handleScore(score) >= 0) {
               awayScores.push_back(score);
            }
        } while(score < 0);

        cout << i << "Q home team score:" << endl;
        do {
            cout << "Please enter a number (0 or greater): ";
            cin >> score;
            if(handleScore(score) >= 0) {
                homeScores.push_back(score);
            }
        } while(score < 0);
    }

    for (int s : awayScores) {
        totalAwayScores += s;
    }

    for (int s : homeScores) {
        totalHomeScores += s;
    }

    if(totalAwayScores == totalHomeScores) {
       isTie = true;
    }

    int i = 5;
    while(isTie) {
        cout << "It's a tie! Let's play another quarter." << endl;

        cout << i << "Q away team score:" << endl;
        do {
            cout << "Please enter a number (0 or greater): ";
            cin >> score;
            if(handleScore(score) >= 0) {
                awayScores.push_back(score);
            }
        } while(score < 0);

        cout << i << "Q home team score:" << endl;
        do {
            cout << "Please enter a number (0 or greater): ";
            cin >> score;
            if(handleScore(score) >= 0) {
                homeScores.push_back(score);
            }
        } while(score < 0);
        if (awayScores[awayScores.size() - 1] != homeScores[homeScores.size() - 1]) {
          isTie = false;
        }
        i++;
    }

    cout << endl;

    totalHomeScores = 0;
    totalAwayScores = 0;
    for (int s : awayScores) {
        totalAwayScores += s;
    }

    for (int s : homeScores) {
        totalHomeScores += s;
    }

    cout << setw(7);
    for (int j = 1; j < i; j++) {
        cout << j << "Q" << setw(3);
    }
    cout << setw(6) << " TOTAL" << endl;

    cout << "AWAY" << setw(4);
    for (int s : awayScores) {
        cout << s << setw(4);
    }
    cout << setw(6) << totalAwayScores << endl;

    cout << "HOME" << setw(4);
    for (int s : homeScores) {
        cout << s << setw(4);
    }
    cout << setw(6) << totalHomeScores << endl;

    return 0;
}

int handleScore(int score) {
    if (score >= 0) {
        return score;
    } else {
        cout << "This is not a valid number! Please try again." << endl;
        return score;
    }
}
