#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int handleInput(int, bool&);

int main() {
    vector<int> numberList;
    vector<int> meanList;
    int input;
    bool isFlagTriggered = false;

    // While the flag is NOT triggered, run the following
    while(!isFlagTriggered) {
        cout << "Please enter an integer (2 or greater, -1 to finish): ";
        cin >> input;

        /* If input doesn't return a value bigger than 0,
         * The loop will just iterate again, and ask for a new input.
         * If input is -1, handleInput function will change the flag's value
         * since -1 doesn't pass the if's condition, the loop will just terminate.
         */
        input = handleInput(input, isFlagTriggered);

        if (input >= 2) {
            numberList.push_back(input);
            int arraySize = numberList.size();
            int total = 0;

            // Sum current value of the loop's iteration to accumulator.
            for (int val : numberList) {
                total += val;
            }

            double result = static_cast<double>(total) / arraySize;

            /*
             * fmod returns the remainder of a floating point division.
             * therefore, if it does not return 0, there is a non-zero decimal.
             */
            if(fmod(result, 1) != 0) {
                cout << "The new arithmetic mean is " << result << endl;
                cout << "Sorry, your input was rejected and will be removed!" << endl;
                numberList.pop_back();
            } else {
                cout << "The new arithmetic mean is " << result << endl;
                cout << "Your input has been accepted!" << endl;
                meanList.push_back(result); // Push division result to vector to be printed later.
            }
            cout << endl;
        }
    }

    cout << "Vector Elements:" << endl;

    for (int i = 0; i < numberList.size(); i++) {
        cout << "numbers["<<i<<"] = " << numberList[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < meanList.size(); i++) {
        cout << "Mean of the first " << i+1 << " element(s): " << meanList[i] << endl;
    }

    return 0;
}

int handleInput(int num, bool& flag) {
    if (num == -1) {
        flag = true; // flag is triggered, change flag to true and terminate loop.
        cout << endl;
        return 0;
    }
    else if (num >= 2) {
       return num;
    }
    else {
        cout << "That is not a valid number! Please try again." << endl;
        cout << endl;
        return 0;
    }
}
