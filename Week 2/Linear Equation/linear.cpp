#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Point A's coordinates;
    double xCoordinateA;
    double yCoordinateA;

    // Point B's coordinates;
    double xCoordinateB;
    double yCoordinateB;

    double slope;
    double yIntercept;

    cout << "Please enter the x coordinate of point A: ";
    cin >> xCoordinateA;
    cout << "Please enter the y coordinate of point A: ";
    cin >> yCoordinateA;

    cout << "Please enter the x coordinate of point B: ";
    cin >> xCoordinateB;
    cout << "Please enter the y coordinate of point B: ";
    cin >> yCoordinateB;

    // Finding delta y over delta x for slope
    slope = (yCoordinateB - yCoordinateA) / (xCoordinateB - xCoordinateA);
    cout << "The slope is " << slope << endl;

    // b = y1 - x1 * m
    yIntercept = yCoordinateA - xCoordinateA * slope;

    cout << "The y-intercept is " << yIntercept << endl;
    cout << "The linear equation in slope-intercept form is y = " << slope << "x + " << yIntercept;

    return 0;
}
