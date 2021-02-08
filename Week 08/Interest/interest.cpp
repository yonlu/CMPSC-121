#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calcFutureValue(double, double, int);
double validateInput(double);
int validateInput(int);

int main() {
    double principal = 0.0;
    double interestRate = 0.0;
    int timeInMonths = 0;
    double total = 0;

    do {
        cout << "What is the initial amount deposited (in dollars): ";
        cin >> principal;
    } while(validateInput(principal) ==  -1.0); // If principal is 0 or negative, ask for a new input.

    do {
        cout << "What is the interest rate: ";
        cin >> interestRate;
    } while (validateInput(interestRate) == -1.0); // If interest rate is 0 or negative, ask for a new input.

    do {
        cout << "What is the amount of time in months: ";
        cin >> timeInMonths;
    } while(validateInput(timeInMonths) == -1); // If month is not between 1 and 12 (inclusive), ask for a new input.

    total = calcFutureValue(principal, interestRate, timeInMonths);

    cout << fixed << setprecision(2);
    cout << "The total value of the account will be: $" << total << endl;

    return 0;
}

/*
 * Following the formula: F = P(1 + i)^t
 * Where F is the future value,
 * P is the principal value (initial value),
 * i is the interest rate expressed as a decimal,
 * and t is the number of months.
 */

double calcFutureValue(double principal, double interest, int months) {
    return principal * pow((1+interest), months);
}

// Principal or Interest rate can not be negative!
double validateInput(double principalOrInterest) {
    if(principalOrInterest <= 0) {
       cout << "Please enter a positive non-zero value!" << endl;
       return -1.0;
    } else {
        return principalOrInterest;
    }
}

// Time must be in months, therefore it should be between 1 and 12 (inclusive).
int validateInput(int months) {
    if (months >= 1 && months <= 12) {
        return months;
    } else {
        cout << "Please enter a valid value for month! Between 1 and 12." << endl;
        return -1;
    }
}

