#include <iostream>
#include <random>

using namespace std;

void getUserSelection(int*);
void determineWinner(int uChoice, int cChoice, int* uScore, int* cScore);

int main() {
    int userChoice = 0;
    int computerChoice = 0;
    int userScore = 0;
    int computerScore = 0;

    // Game constants
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 3;

    // Game RNG
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);

    // While sentinel is not activated
    while (userChoice != -1) {
        getUserSelection(&userChoice);
        computerChoice = dist(rd);
        if (userChoice > 0 && userChoice < 4) {
            determineWinner(userChoice, computerChoice, &userScore, &computerScore);
            cout << endl;
        }
    }

    cout << "\nGAME OVER" << endl;
    if (userScore > computerScore) {
        cout << "The user wins with a score of " << userScore << " to " << computerScore << "." << endl;
    }
    else if (userScore < computerScore) {
        cout << "The computer wins with a score of " << computerScore << " to " << userScore << "." << endl;
    } else {
        cout << "It's a tie! With a score of " << userScore << " to " << computerScore << "." << endl;
    }

    return 0;
}

void getUserSelection(int* choice) {
    cout << "Make your choice (1: rock, 2: paper, 3: scissors, -1: quit) ";
    int userInput = 0;
    cin >> userInput;
    if(cin.fail()) {
        userInput = 0;
        *choice = userInput;
        return;
    }
    if (userInput == -1) {
        *choice = -1;
        return;
    }
    if (userInput > 0 && userInput < 4) {
        *choice = userInput;
    } else {
        *choice = userInput;
       cout << "\nPlease enter a valid choice."
       << " (1: rock, 2: paper, 3: scissors, -1: quit)" << endl;
    }
}

void determineWinner(int uChoice, int cChoice, int* uScore, int* cScore) {
   if(uChoice == -1) {
       return;
   }
   if (uChoice == 1) {
       cout << "user chooses rock, ";
       switch(cChoice) {
           case 1:
               cout << "computer chooses rock." << endl;
               cout << "IT'S A TIE!" << endl;
               break;
           case 2:
               cout << "computer chooses paper." << endl;
               cout << "COMPUTER WINS" << endl;
               *cScore += 1;
               break;
           case 3:
               cout << "computer chooses scissors." << endl;
               cout << "USER WINS" << endl;
               *uScore += 1;
               break;
           default:
               break;
       }
   }
   else if (uChoice == 2) {
        cout << "user chooses paper, ";
        switch(cChoice) {
            case 1:
                cout << "computer chooses rock." << endl;
                cout << "USER WINS" << endl;
                *uScore += 1;
                break;
            case 2:
                cout << "computer chooses paper." << endl;
                cout << "IT'S A TIE" << endl;
                break;
            case 3:
                cout << "computer chooses scissors." << endl;
                cout << "COMPUTER WINS" << endl;
                *cScore += 1;
                break;
            default:
                break;
        }
    }
    else if (uChoice == 3) {
        cout << "user chooses scissors, ";
        switch (cChoice) {
            case 1:
                cout << "computer chooses rock." << endl;
                cout << "COMPUTER WINS" << endl;
                *cScore += 1;
                break;
            case 2:
                cout << "computer chooses paper." << endl;
                cout << "USER WINS" << endl;
                *uScore += 1;
                break;
            case 3:
                cout << "computer chooses scissors." << endl;
                cout << "IT'S A TIE" << endl;
                break;
            default:
                break;
        }
    }
}
