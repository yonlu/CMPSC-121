#include <iostream>
#include <string>

using namespace std;

bool verifyAnswer(bool, bool);
bool getUserAnswer();

int main() {
    string questions[4];
    bool answers[4];
    int score = 0;

    cout << "Let's build a trivia of true or false questions!";
    cout << endl;

    // Get questions for the trivia:
    for (int i = 0; i < 4; i++) {
        cout << endl;
        // Ask user for a question
        string question;
        cout << "Please enter Question " << i+1 << ": " << endl;
        getline(cin, question);
        questions[i] = question;

        // Ask user for the corresponding answer, and validate it
        // Only accept valid answers, T, t, True, true; F, f, False and false.
        answers[i] = getUserAnswer();
    }

    cout << endl;
    cout << "Let's play the game!" << endl;

    string  answer;
    for (int i = 0; i < 4; i++) {
       cout << endl;
       cout << "Question " << i+1 << ":" << endl;
       cout << questions[i] << endl;

       cout << "Please enter a guess: (T, t, True, true, F, f, False, false):" << endl;
       getline(cin, answer);
        bool flagIsTriggered; // Keep looping until flag is triggered
        do {
            if (!(answer.compare("T") && answer.compare("t") && answer.compare("True") && answer.compare("true"))) {

                flagIsTriggered = false;
                if(verifyAnswer(true, answers[i])) {
                    score++;
                }
            }
            else if(!(answer.compare("F") && answer.compare("f") && answer.compare("False") && answer.compare("false"))) {
                flagIsTriggered = false;
                if(verifyAnswer(false, answers[i])) {
                    score++;
                }
            } else {
                flagIsTriggered = true;
                cout << "Invalid input, try again!" << endl;
                cout << "Please enter a guess  (T, t, True, true, F, f, False, false):" << endl;
                getline(cin, answer);
            }
        } while(flagIsTriggered);
    }

    cout << endl;

    cout << "You guessed " << score << " out of 4 questions correctly!" << endl;

    return 0;
}

bool getUserAnswer() {
    string answer;

    static int index = 1;

    cout << "Please enter Answer " << index << " (T, t, True, true, F, f, False, false):" << endl;
    getline(cin, answer);

    bool flagIsTriggered; // Keep looping until flag is triggered
    do {
        if (!(answer.compare("T") && answer.compare("t") && answer.compare("True") && answer.compare("true"))) {
            flagIsTriggered = false;
            index++;
            return true;
        }
        else if(!(answer.compare("F") && answer.compare("f") && answer.compare("False") && answer.compare("false"))) {
            flagIsTriggered = false;
            index++;
            return false;
        } else {
            flagIsTriggered = true;
            cout << "Invalid input, try again!" << endl;
            cout << "Please enter Answer " << index << " (T, t, True, true, F, f, False, false):" << endl;
            getline(cin, answer);
        }
    } while(flagIsTriggered); // clion eh meio burro as vezes
}

bool verifyAnswer(bool userAnswer, bool realAnswer) {
    return userAnswer == realAnswer;
}
