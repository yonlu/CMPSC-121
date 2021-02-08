#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void isScoreValid(double, bool&);

int main() {
    string movieName;
    double averageScore = 0.0;
    double *averagePointer = &averageScore;
    double scores[5];
    double score = 0.0;
    bool isValid = false;

    cout << fixed << setprecision(2);
    cout << "What is the name of the movie?" << endl;
    getline(cin, movieName);

    for (int i = 0; i < 5; i++) {
        do {
            cout << "Enter score " << i+1 << ": ";
            cin >> score;
            isScoreValid(score, isValid);
        } while(!isValid);

       *(scores + i) = score;
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        *averagePointer += *(scores + i);
    }

    *averagePointer /= 5;

    cout << "The average score for " << movieName
    << " is " << *averagePointer << endl;

    return 0;
}

void isScoreValid(double score, bool& isValid) {
    if (score >= 0 && score <= 10) {
        isValid = true;
    } else {
        isValid = false;
        cout << "Please enter a score between 0 and 10" << endl;
    }
}
