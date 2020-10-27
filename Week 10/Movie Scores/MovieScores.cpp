#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string movieName;
    double averageScore = 0.0;
    double scores[5];

    cout << fixed << setprecision(2);
    cout << "What is the name of the movie?" << endl;
    getline(cin, movieName);

    for (int i = 0; i < 5; i++) {
      cout << "Enter score " << i+1 << ": ";
      cin >> *(scores + i);
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        averageScore += *(scores + i);
    }

    averageScore /= 5;

    cout << "The average score for " << movieName
    << " is " << averageScore << endl;

    return 0;
}
