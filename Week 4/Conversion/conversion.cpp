#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Sets precision for 2 decimal places throughout the program
    cout << fixed << setprecision(2);

    double fahrenheitOne = 0.0;
    double fahrenheitTwo = 0.0;
    double fahrenheitThree = 0.0;
    double fahrenheitFour  = 0.0;
    double fahrenheitFive = 0.0;

    double celsiusOne = 0.0;
    double celsiusTwo = 0.0;
    double celsiusThree = 0.0;
    double celsiusFour  = 0.0;
    double celsiusFive = 0.0;

    cout << "Enter five temperature values in Fahrenheit: ";
    cin >> fahrenheitOne >> fahrenheitTwo >> fahrenheitThree >> fahrenheitFour >> fahrenheitFive;

    // Convert Fahrenheit to celsius.
    celsiusOne = (fahrenheitOne - 32) * 5/9;
    celsiusTwo = (fahrenheitTwo - 32) * 5/9;
    celsiusThree = (fahrenheitThree - 32) * 5/9;
    celsiusFour = (fahrenheitFour - 32) * 5/9;
    celsiusFive = (fahrenheitFive - 32) * 5/9;

    // Printing a formatted table of temperatures
    // Table Headers
    cout << right << setw(10) << "\nFahrenheit";
    cout << right << setw(13) << "Celsius";
    cout << right << setw(15) << "Warning" << endl;

    // First row
    cout << setw(10) << right << fahrenheitOne  <<
    setw(13) << celsiusOne;

    // Check temperature warnings
    if (celsiusOne <= 0) {
        cout << setw(15) << right << "<= Freezing!" << endl;
    }
    else if (celsiusOne >= 100) {
        cout << setw(15) << right << ">= Boiling!" << endl;
    } else {
        cout << endl;
    }

    // Second row
    cout << setw(10) << right << fahrenheitTwo <<
    setw(13) << celsiusTwo;

    // Check temperature warnings
    if (celsiusTwo <= 0) {
        cout << setw(15) << right << "<= Freezing!" << endl;
    }
    else if (celsiusTwo >= 100) {
        cout << setw(15) << right << ">= Boiling!" << endl;
    } else {
        cout << endl;
    }

    // Third row
    cout << setw(10) << right << fahrenheitThree <<
    setw(13) << celsiusThree;

    // Check temperature warnings
    if (celsiusThree <= 0) {
        cout << setw(15) << right << "<= Freezing!" << endl;
    }
    else if (celsiusThree >= 100) {
        cout << setw(15) << right << ">= Boiling!" << endl;
    } else {
        cout << endl;
    }

    // Fourth row
    cout << setw(10) << right << fahrenheitFour <<
    setw(13) << celsiusFour;

    // Check temperature warnings
    if (celsiusFour <= 0) {
        cout << setw(15) << right << "<= Freezing!" << endl;
    }
    else if (celsiusFour >= 100) {
        cout << setw(15) << right << ">= Boiling!" << endl;
    } else {
        cout << endl;
    }

    // Fifth row
    cout << setw(10) << right << fahrenheitFive <<
    setw(13) <<  celsiusFive;

    // Check temperature warnings
    if (celsiusFive <= 0) {
        cout << setw(15) << right << "<= Freezing!" << endl;
    }
    else if (celsiusFive >= 100) {
        cout << setw(15) << right << ">= Boiling!" << endl;
    } else {
        cout << endl;
    }

    return 0;
}
