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

    double distance = computeDistance(speed, height);
    double maxHeight = computeMaxHeight(speed, height);

//    cout << "PROJECTILE IMPACT AFTER " << setprecision(1) << timeOfFlight << setprecision(2) <<
//    " SECONDS" << endl;
//
//    cout << "Max height was at " << timeMaxHeight << " seconds";
//    cout << " with a height of " << maxHeight << " meters." << endl;

cout << distance << endl;
cout << maxHeight << endl;

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

    /*
     * Yf = Yi + Vyi * t + 1/2 a * t^2
     *
     * 0 = initialHeight + initialSpeed * t + 1/2 * 9.8 * t^2
     */

    double distanceAboveGround = initialHeight;

    // Printing table of values, 0.1 second intervals
    for(double i = 0; distanceAboveGround >= 0; i += 0.1) {
       distanceAboveGround = initialHeight + initialSpeed * i + 0.5 * -9.8 * pow(i, 2);
       cout << setprecision(1) << i << setprecision(2) << setw(10) << distanceAboveGround << endl;
    }

    return distanceAboveGround;
}

