#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Setting fixed precision for currency standards
    cout << fixed << setprecision(2);

    string firstItem = "";
    double firstPrice = 0;

    string secondItem = "";
    double secondPrice = 0;

    cout << "What is the name of the first item: ";
    cin >> firstItem;

    cout << "How much did it cost? ";
    cin >> firstPrice;

    cout << "What is the name of the second item: ";
    cin >> secondItem;

    cout << "How much did it cost? ";
    cin >> secondPrice;

    // Prints receipt with item name being left justified
    cout << "\nRECEIPT" << endl;
    cout << left << setw(20) << firstItem << "$" << setw(5) << right << firstPrice << endl ;
    cout << left << setw(20) << secondItem << "$" << setw(5) << right << secondPrice << endl ;
    cout << left << setw(20) << "Total" << "$" << setw(5) << right << firstPrice + secondPrice << endl ;

    return 0;
}
