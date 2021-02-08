#include <iostream>
#include <vector>

using namespace std;

double validateInput(double, bool&);
double validateValues(double, bool&);
double calculateYValue(double, double, double);

int main() {
    bool isValid = false;
    double slope = 0.0;
    double yIntercept = 0.0;
    double xValue;
    vector<double> xValues;


    while(!isValid) {
        cout << "Please enter the slope of the line: ";
        cin >> slope;
        validateInput(slope, isValid);
    }

    isValid = false;

    while(!isValid) {
       cout << "Please enter the y-intercept ";
       cin >> yIntercept;
       validateInput(yIntercept, isValid);
    }

    isValid = false;

    cout << "Now enter all of the non-negative x values you wish to find the"
    << " y value for, type -1 when done." << endl;

    while(!isValid) {
        cin >> xValue;
        validateValues(xValue, isValid);
        if (xValue >= 0) {
            xValues.push_back(xValue);
        }
    }

    cout << "Results" << endl;
    cout << "x | y" << endl;
    for (double value : xValues) {
        cout << value << " | " << calculateYValue(slope, value, yIntercept) << endl;
    }

    return 0;
}

double validateInput(double number, bool& isValid) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a numerical value" << endl;
        cout << endl;
    }
    else {
        isValid = true;
        return number;
    }

    return 0;
}

double validateValues(double number, bool& flagIsTriggered) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a numerical value" << endl;
        cout << endl;
    }
    else if(number == -1) {
        flagIsTriggered = true;
        cout << endl;
        return -1;
    }
    else if(number >= 0) {
        cout << "OK" << endl;
        return number;
    } else {
        cout << "Please enter a positive number, or -1 to terminate." << endl;
        return -1;
    }

    return 0;
}

double calculateYValue(double slope, double xValue, double yIntercept) {
   return slope * xValue + yIntercept;
}