#include <iostream>
#include <iomanip>

using namespace std;

int getScore(int);
double calcAverage(int, int, int, int);
int dropLowest(int, int, int, int);
void sortScores(int[]);

int main() {
    int firstScore, secondScore, thirdScore, fourthScore = 0;

    do {
        cout << "Enter the first test score: ";
        cin >> firstScore;
    } while(getScore(firstScore) == -1);

    do {
        cout << "Enter the test second score: ";
        cin >> secondScore;
    } while(getScore(secondScore) == -1);

    do {
        cout << "Enter the test third score: ";
        cin >> thirdScore;
    } while(getScore(thirdScore) == -1);

    do {
        cout << "Enter the test fourth score: ";
        cin >> fourthScore;
    } while(getScore(fourthScore) == -1);

    double average = calcAverage(firstScore, secondScore, thirdScore, fourthScore);
    cout << fixed << setprecision(1);
    cout << "The average test score is: " << average << "%" << endl;

    return 0;
}

int getScore(int score) {
    if (score >= 0 && score <= 100) {
       return score;
    } else {
        cout << "Invalid score, enter a score between 0 and 100 (inclusive)" << endl;
        return -1;
    }
}

double calcAverage(int firstScore, int secondScore, int thirdScore, int fourthScore) {
    // dropLowest will call an ascending order sorting function.
    int lowestScore = dropLowest(firstScore, secondScore, thirdScore, fourthScore);

    cout << "Lowest score is: " << lowestScore << endl;
    return ((firstScore + secondScore + thirdScore + fourthScore - lowestScore ) / 3.0);
}

int dropLowest(int firstScore, int secondScore, int thirdScore, int fourthScore) {
   int scoreList[] = { firstScore, secondScore, thirdScore, fourthScore };
   sortScores(scoreList);

   // Lowest score is located at array element of index 0.
   return scoreList[0];
}

void sortScores(int scoreList[]) {
    const int ARRAY_SIZE = 4;

    // Bubble sort, lowest score should be in the first element of the array now.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 1; j < ARRAY_SIZE - i; j++) {
           if (scoreList[j] < scoreList[j - 1]) {
            int tmp = scoreList[j];
            scoreList[j] = scoreList[j - 1];
            scoreList[j - 1] = tmp;
           }
        }
    }
}
