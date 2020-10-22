#include <iostream>
#include <string>

using namespace std;

bool verifyAnswer(bool, bool);
bool getUserAnswer();
void askForAnswer(int);

int main() {
    string questions[4];
    bool answers[4];
    int score = 0;

    cout << "Let's build a trivia of true or false questions!" << endl;

    // Get questions for the trivia:
    for (int i = 0; i < 4; i++) {
        // Ask user for a question
        string question;
        cout << "Please enter Question " << i+1 << ": " << endl;
        getline(cin, question);
        questions[i] = question;

        // Ask user for the corresponding answer, and validate it
        string answer;
        askForAnswer(i+1);
        getline(cin, answer);

        bool flagIsTriggered; // Keep looping until flag is triggered
        do {
            if (!(answer.compare("T") && answer.compare("t") && answer.compare("True") && answer.compare("true"))) {
                flagIsTriggered = false;
                answers[i] = true;
            }
            else if(!(answer.compare("F") && answer.compare("f") && answer.compare("False") && answer.compare("false"))) {
                flagIsTriggered = false;
                answers[i] = false;
            } else {
                flagIsTriggered = true;
                cout << "Invalid input, try again!" << endl;
                askForAnswer(i+1);
                getline(cin, answer);
            }
        } while(flagIsTriggered);
    }


    cout << endl;
    cout << "Let's play the game!" << endl;
    cout << endl;

    string input;
    for (int i = 0; i < 4; i++) {
       cout << "Question " << i+1 << ":" << endl;
       cout << questions[i] << endl;

       cout << "Please enter a guess: (T, t, True, true, F, f, False, false):" << endl;
       cin >> input;
    }

    return 0;
}

void askForAnswer(int index) {
    cout << "Please enter Answer " << index << " (T, t, True, true, F, f, False, false): " << endl;
}

bool getUserAnswer() {
    string answer;
    cout << "Please enter Answer " << index << " (T, t, True, true, F, f, False, false): " << endl;
    cin >> answer;
}
