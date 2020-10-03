#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int rows = 0;
    int columns = 0;
    int tableHeader = 1;
    int headerColumn = 1;

    bool isRangeAcceptable = false;
    cout << "Let's build a multiplication table!" << endl;

    do {
        // Get rows
        cout << "Enter the number of rows (1 to 12 inclusive): ";
        cin >> rows;

        // If it is between 1 and 12, inclusive.
        if (rows >= 1 && rows <= 12) {
            // Range is acceptable.
           isRangeAcceptable = true;
        } else {
           isRangeAcceptable = false;
           cout << "Invalid input; try again!" << endl;
        }

    } while(!isRangeAcceptable); // If the range is NOT acceptable, ask again.

    do {
        // Get columns
        cout << "Enter the number of columns (1 to 12 inclusive): ";
        cin >> columns;

        // If it is between 1 and 12, inclusive.
        if (columns >= 1 && columns <= 12) {
            // Range is acceptable.
            isRangeAcceptable = true;
        } else {
            isRangeAcceptable = false;
            cout << "Invalid input; try again!" << endl;
        }

    } while(!isRangeAcceptable); // If the range is NOT acceptable, ask again.

    // Print table headers, from 1 to 12 (inclusive), according to column's value
    cout << setw(10); // Initial spacing for initial empty table cell, 0 is not in a multiplication table
    for (int i = 0; i < columns; i++) {
        cout << tableHeader++ << setw(5); // Spacing between table headers
    }

    // Break line to separate table headers from the table itself
    cout << endl;

    /*
     * Print the product of the table header with the header column
     * For example:
     *
     * let tableHeader = 1 and headerColumn = 1;
     * product = 1 * 1 => 1
     *
     * let tableHeader = 3 and headerColumn = 4;
     * product = 3 * 4 => 12
     *
     */
    for (int i = 1; i <= rows; i++) { // Initialize at 1, so we don't up doing multiplication with 0.
        cout << setw(5) << headerColumn++; // setw(5) makes triple digit numbers better to read, like 12 * 12 = 144
        for (int j = 1; j <= columns; j++) {
            cout << setw(5) << i*j;
        }
        cout << endl;
    }

    return 0;
}
