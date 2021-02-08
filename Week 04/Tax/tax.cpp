#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double price = 0;
    string state;
    double tax = 0.0;

    // tmp variable to clear buffer
    string tmp;

    cout << fixed << setprecision(2);

    cout << "What is the price of the item? ";
    cin >> price;

    // Clear cin buffer
    getline(cin, tmp);

    cout << "What state are you purchasing in? ";
    getline(cin, state);

    if (state == "PA") {
       tax = price * 0.06;
    }
    else if (state == "NY") {
        tax = price * 0.04;
    }
    else if (state == "NH") {
        tax = 0.00;
    } else {
        cout << "This program cannot calculate tax in that state...shutting down." << endl;
        return 1;
    }

    cout << "The total sales tax in " << state << " on your $" << price << " purchase is $" << tax << endl;
    return 0;
}
