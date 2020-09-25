#include <iostream>

using namespace std;

int main() {
    int firstNumber = 0;
    int secondNumber = 0;
    double total = 0;
    char operation = ' ';

    cout << "What is the first number? ";
    cin >> firstNumber;

    cout << "What is the second number? ";
    cin >> secondNumber;

    cout << "What is the operation? ";
    cin >> operation;


    switch(operation) {
        case '+': {
            total = firstNumber + secondNumber;
            cout << firstNumber << " " << operation << " " << secondNumber << " = " << total << endl;
            break;
        }

        case '-': {
            total = firstNumber - secondNumber;
            cout << firstNumber << " " << operation << " " << secondNumber << " = " << total << endl;
            break;
        }

        case '*': {
            total = firstNumber * secondNumber;
            cout << firstNumber << " " << operation << " " << secondNumber << " = " << total << endl;
            break;
        }

        case '/': {
           total = static_cast<double>(1.0 * firstNumber / secondNumber);
           cout << firstNumber << " " << operation << " " << secondNumber << " = " << total << endl;
           break;
        }

        case '%': {
            total = firstNumber % secondNumber;
            cout << firstNumber << " " << operation << " " << secondNumber << " = " << total << endl;
            break;
        }

        default: {
            cout << "Invalid operator, try again.";
            break;
        }
    }
}
