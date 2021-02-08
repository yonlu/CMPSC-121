#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double radius;
    double diameter;
    double area;
    double volume;

    // Asks for user input
    cout << "Please enter a radius in meters: ";
    cin >> radius;

    // Calculates diameter of a circle and then prints it back.
    diameter = radius * 2;
    cout << "The diameter of the circle is " << diameter << "m\n";

    // Calculates area of a circle.
    area = (M_PI * pow(radius,2));
    cout << "The area of the circle is " << area << "m^2\n";

    // Calculates volume of a sphere with the same radius.
    volume = ((4.0/3) * M_PI * pow(radius, 3));
    cout << "The volume of a sphere with the same radius is " << volume << "m^3";


    return 0;
}
