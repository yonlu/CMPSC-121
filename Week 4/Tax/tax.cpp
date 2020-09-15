#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double price = 0;
    string state;
    double tax = 0;

    cout << fixed << setprecision(2);

    cout << "What is the price of the item? ";
    cin >> price;

    // Clear cin buffer
    cin.ignore();

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
        return 1;
    }

    cout << "The total sales tax in " << state << " on your $" << price << " purchase is $" << tax << endl;
    return 0;
}
