#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double valueA = 0;
    double valueB = 0;
    double valueC = 0;

    cout << "What is the a value: ";
    cin >> valueA;

    cout << "What is the b value: ";
    cin >> valueB;

    cout << "What is the c value: ";
    cin >> valueC;

    // Quadratic formula as in: (-b + or - sqrt(b^2 - 4ac))/2a
    double quadraticOne = ((-valueB) + sqrt(pow(valueB, 2) - 4 * (valueA * valueC)))/(2*valueA);
    double quadraticTwo = ((-valueB) - sqrt(pow(valueB, 2) - 4 * (valueA * valueC)))/(2*valueA);

    cout << "The two points are (" << quadraticOne << ", 0) and (" << quadraticTwo << ", 0)" << endl;

    return 0;
}
