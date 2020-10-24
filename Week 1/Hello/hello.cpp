#include <iostream>

using namespace std;

void func1(double, int);

int main() {
    int x = 0;
    double y = 1.5;

    cout << x << " " << y << endl;
    func1(y, x);
    cout << x << " " << y << endl;

    return 0;
}

void func1(double a, int b) {
    cout << a << " " << b << endl;
    a = 0.0;
    b = 10;
    cout << a << " " << b << endl;
}

