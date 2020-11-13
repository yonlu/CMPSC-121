#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int y = 0;

    int *xPtr = &x;
    int *yPtr = &y;

    cout << xPtr << endl;
}

