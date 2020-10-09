#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double computeMaxHeight(double, double);
double computeDistance(double, double);

int main() {
    double speed = 0.0;
    double height = 0.0;

    cout << fixed << setprecision(2);

    cout << "Enter a starting speed in m/s: ";
    cin >> speed;

    cout << "Enter a starting height in meters: ";
    cin >> height;

    double maxHeight = computeDistance(speed, height);
    double timeOfFlight = 2 * speed / 9.8;
    double timeMaxHeight = timeOfFlight/2;

    cout << "PROJECTILE IMPACT AFTER " << setprecision(1) << timeOfFlight << setprecision(2) <<
    " SECONDS" << endl;

    cout << "Max height was at " << timeMaxHeight << " seconds";
    cout << " with a height of " << maxHeight << " meters." << endl;

    return 0;
}

double computeMaxHeight(double initialSpeed, double initialHeight)  {
    return static_cast<double>(pow(initialSpeed, 2) / (2 * 9.8) + initialHeight);
}

double computeDistance(double initialSpeed, double initialHeight) {
    /*
     * d = -1/2 * a * t^2 + Vi * t + di
     *
     * Vi and di are given as parameters.
     * When d = 0 terminate loop
     *
     */

    double distanceAboveGround = 0.0;
    double maxHeight = computeMaxHeight(initialSpeed, initialHeight);
    double timeOfFlight = 2 * initialSpeed / 9.8;

    // Printing table of values, 0.1 second intervals
    for(double i = 0; i <= timeOfFlight; i += 0.1) {
        distanceAboveGround = -1 * 0.5 * 9.8 * pow(i, 2) + initialSpeed * i + initialHeight;
        cout << setprecision(1) << i << setprecision(2) << setw(10) << distanceAboveGround << endl;
    }


    return maxHeight;
}

