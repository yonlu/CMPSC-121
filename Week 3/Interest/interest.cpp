/**
 * interest.cpp:
 * Asks a user for a principal, interest rate and how many timer a year the interest is compounded;
 * then computes the total balance and the interest earned.
 *
 * @author Lucas Sallada
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double principal = 0.0;
    double rate = 0.0;
    double timesPerYear = 0.0;
    double amount = 0.0;

    cout << fixed << setprecision(2);

    cout << "What is the principal: ";
    cin >> principal;

    cout << "What is the interest rate? ";
    cin >> rate;

    cout << "How many times per year is the interest compounded? ";
    cin >> timesPerYear;

    amount = principal * pow((1 + (rate/timesPerYear)), timesPerYear);

    cout << "Total balance: $" << amount << endl;
    cout << "Interest earned: $" << amount - principal << endl;

    return 0;
}
