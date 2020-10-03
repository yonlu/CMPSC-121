#include <iostream>

using namespace std;

int main() {
    int year = 0;
    bool isLeapYear = false;

    cout << "Please enter a 4-digit year ";
    cin >> year;

    /*
     * Is year divisible by 100? If true, check if it is by 400, if false check if it is by 4.
     *
     * Leap year has two exceptions, however, the original exception itself has an exception
     * The original exception is: divisible by 4 but also by 100, then it isn't a leap year.
     * And the exception's exception: divided by 100 but also 400, then it is a leap year.
     *
     * If we check by 100 first, we can determine if the we need to check for the exception's exception
     * If the exception is true (year % 100 == 0), check for exception's exception (year % 400 == 0)
     * A year that is divisible by 400, is automatically also divisible by 4. 400 is a common multiple of 4.
     * If the exception is false, it might be divisible by 4 (year % 4 == 0)
     * If the last check is true, it is a leap year.
     */
    // Not sure if this counts for the twist
    //isLeapYear = year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;

    // If else variant for the twist, more straightforward logic
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        isLeapYear = true;
    } else {
        isLeapYear = false;
    }

    if (isLeapYear) {
       cout << year << " is a leap year!" << endl;
    } else {
        cout << year << " is NOT a leap year!" << endl;
    }

    return 0;
}
