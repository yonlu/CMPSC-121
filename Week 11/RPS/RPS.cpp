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
            switch (userChoice) {
                case 1:
                    cout << "user chooses rock, ";
                    break;
                case 2:
                    cout << "user chooses paper, ";
                    break;
                case 3:
                    cout << "user chooses scissors, ";
                default:
                    break;
            }
            switch (computerChoice) {
                case 1:
                    cout << "computer chooses rock." << endl;
                    break;
                case 2:
                    cout << "computer chooses paper." << endl;
                    break;
                case 3:
                    cout << "computer chooses scissors." << endl;
                    break;
                default:
                    break;
            }
            determineWinner(userChoice, computerChoice, &userScore, &computerScore);
        }
    }

    cout << endl;
    cout << "GAME OVER" << endl;
    if (userScore > computerScore) {
        cout << "The user wins with a score of " << userScore << " to " << computerScore << ".";
    }
    else if (userScore < computerScore) {
        cout << "The computer wins with a score of " << computerScore << " to " << userScore << ".";
    } else {
        cout << "It's a tie! With a score of " << userScore << " to " << computerScore << ".";
    }

    return 0;
}

void getUserSelection(int* userChoicePointer) {
    cout << "Make your choice (1: rock, 2: paper, 3: scissors, -1: quit) ";
    int choice = 0;
    cin >> choice;
    if(cin.fail()) {
        choice = 0;
        *userChoicePointer = choice;
        return;
    }
    if (choice == -1) {
        *userChoicePointer = -1;
        return;
    }
    if (choice > 0 && choice < 4) {
        *userChoicePointer = choice;
    } else {
        *userChoicePointer = choice;
       cout << "Please enter a valid choice."
       << " (1: rock, 2: paper, 3: scissors, -1: quit)" << endl;
    }
}

void determineWinner(int uChoice, int cChoice, int* uScore, int* cScore) {
    if(uChoice == -1) {
        return;
    }
    /*
     * User wins Scenario:
     * let computerChoice = 3
     * let userChoice = 1
     *
     * computerChoice % 3 + 1 == userChoice ?
     * 3 % 3 => 0
     * 0 + 1 => 1
     * Is 1 == 1 ? => True
     * User wins.
     *
     *
     * User loses Scenario:
     * let computerChoice = 1
     * let userChoice = 3
     *
     * computerChoice % 3 + 1 == userChoice ?
     * 1 % 3 => 1
     * 1 + 1 => 2
     * Is 2 == 3 ? => False
     *
     * check else if
     * userChoice % 3 + 1 == computerChoice
     * 3 % 3 => 0
     * 0 + 1 => 1
     * Is 1 == 1 ? => True
     *
     * Users loses.
     *
     * It's a tie Scenario:
     * let computerChoice = 1
     * let userChoice = 1
     *
     * computerChoice % 3 + 1 == userChoice ?
     * 1 % 3 => 1
     * 1 + 1 => 2
     * Is 2 == 1 ? => False
     *
     * check else if
     * userChoice % 3 + 1 == computerChoice
     * 1 % 3 => 1
     * 1 + 1 => 2
     * Is 2 == 1 ? => false
     *
     * It's a tie.
     */

   if (cChoice % 3 + 1 == uChoice) {
       cout << "USER WINS" << endl;
       *uScore += 1;
   }
   else if (uChoice % 3 + 1 == cChoice) {
       cout << "USERS LOSES" << endl;
       *cScore += 1;
   } else {
       cout << "IT'S A TIE!"  << endl;
   }
   cout << endl;
}
