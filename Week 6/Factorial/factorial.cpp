#include <iostream>

using namespace std;

int main() {
    int number = 0;
    int factorial = 0;
    bool isRangeAcceptable;

    do {
        cout << "Enter a number to calculate its factorial ";
        cin >> number;

        bool isNegative = (number < 0);
        bool isTooBig = (number > 12);

        if (isNegative) {
         cout << "Can't calculate the factorial of a negative number." << endl;
         isRangeAcceptable = false;
        }
        else if (isTooBig) {
            cout << "Factorial too big." << endl;
            isRangeAcceptable = false;
        } else {
            isRangeAcceptable = true;
        }

    } while(!isRangeAcceptable);


    /*
     * Factorial formula: n! = n * (n - 1) * (n - 2).... * 1.
     *
     * let n = 4.
     * 4! = 4 * (4 - 1) * (4 - 2)....
     *
     * let i = 1
     * swap decrementor with i.
     *
     * number = number * (number - i)
     * number = 4 * (4 - 1) => 4 * 3 => 12
     * number = 12 * (4 - 2) => 12 * 2 => 24
     * number = 24 * (4 - 3) => 24 * 1 => 24
     */

    // Is number 0? If true, factorial is 1, otherwise do nothing.
    number == 0 ? factorial = 1 :
    factorial = number;

    for (int i = 1; i < number; i++) {
        factorial *= (number - i);
    }

    cout << number << "!" << " = " << factorial << endl;

    return 0;
}
