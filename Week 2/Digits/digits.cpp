/**
 * digits.cpp:
 * Asks a user for a four digit number, sums the digits and prints the result; repeat this summation two more times
 *
 * @author Lucas Sallada
 */
#include <iostream>

using namespace std;

/**
 *
 * Function main, begins with program execution
 *
 * @return The result of program execution
 */
int main() {
    // 1. Get a value from the user
    int number = 0;

    cout << "Please input a four-digit number:";
    cin >> number;

    // 2. Mod the value by 10 to get the first digit
    int digit1 = number % 10;

    // 3. Divide by 10 to "lop off" the first digit
    number /= 10;

    // 4. Repeat steps 2 and 3 to get the remaining digits
    int digit2 = number % 10;
    number /= 10;

    int digit3 = number % 10;
    number /= 10;

    int digit4 = number % 10;

    // 5. Sum the digits and display the result
    int sum = digit4 + digit3 + digit2 + digit1;

    cout << "Sum of the digits: ";
    cout << digit4 << " + ";
    cout << digit3 << " + ";
    cout << digit2 << " + ";
    cout << digit1 << " = ";
    cout << sum << endl;

    // 6. Repeat steps 2-5 twice
    // Second calculation, sum of the digits of the sum.
    number = sum;

    digit1 = number % 10;
    number /= 10;

    digit2 = number % 10;
    number /= 10;

    digit3 = number % 10;
    number /= 10;

    digit4 = number % 10;
    number /= 10;

    sum = digit4 + digit3 + digit2 + digit1;

    cout << "Sum of the digits of the sum: ";
    cout << digit4 << " + ";
    cout << digit3 << " + ";
    cout << digit2 << " + ";
    cout << digit1 << " = ";
    cout << sum << endl;

    // Third calculation, sum of the digits of the sum of the digits of the sum.
    number = sum;

    digit1 = number % 10;
    number /= 10;

    digit2 = number % 10;
    number /= 10;

    digit3 = number % 10;
    number /= 10;

    digit4 = number % 10;
    number /= 10;

    sum = digit4 + digit3 + digit2 + digit1;

    cout << "Sum of the digits of the sum of the digits of the sum: ";
    cout << digit4 << " + ";
    cout << digit3 << " + ";
    cout << digit2 << " + ";
    cout << digit1 << " = ";
    cout << sum;

    return 0;
}
