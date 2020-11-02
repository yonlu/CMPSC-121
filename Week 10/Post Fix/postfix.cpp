#include <iostream>
#include <vector>
#include <string>

using namespace std;

double convertToDouble(string);
double computeResult(double, double, string);

int main() {
    /*
     * Ask user for number or operator,
     * valid operators: (+, -, *, /)
     * read value into a string
     *
     * if value is a number,
     *  push value to vector
     *
     * else if value is an operator,
     *  pop two values off of the vector
     *  AND compute result given by operator and push the result back onto the vector.
     *
     * Loop this pattern until user enters "d".
     *  then pop last value and print it.
     *  end program.
     *
     * Example:
     * Value1: 2
     * Value2: 2
     * Value3: +
     * Value4: d
     *
     * Result: 4
     *
     * Value 1 => is value a number? (2 == number?) TRUE
     *  then push to vector
     *
     * Value 2 => is value a number? (2 == number?) TRUE
     *  then push to vector
     *
     * Value 3 => is value a number? (+ == number?) FALSE
     *  pop last two values from vector.
     *  and compute: value1 <operator> value2
     *  result: 2 + 2
     *  push result back to vector;
     *
     * Value 4 => is value a number? ('d' == number?) FALSE and FLAG triggered.
     *  pop last value, print it, end program.
     */

    bool flag = false;
    double result;
    vector<string> values;

    do {
        string value;
        cout << "Enter a value or operator: ";
        cin >> value;

        if(value == "+" || value == "-" || value == "*" || value == "/") {
            if(values.size() == 2) {
                double valueOne = convertToDouble(values[values.size() - 1]);
                values.pop_back();

                double valueTwo = convertToDouble(values[values.size() - 1]);
                values.pop_back();

                result = computeResult(valueOne, valueTwo, value);
            } else {
                cout << "Please enter a valid value (you need at least two numbers for an operation)" << endl;
            }

        } else if(value == "d") {
            flag = true;
        } else {
            values.push_back(value);
        }

    } while(!flag);

    cout << "Result: " << result << endl;
    cout << "done" << endl;

    return 0;
}

double convertToDouble(string value) {
   return stod(value);
}

double computeResult(double firstValue, double secondValue, string arithmeticOperator) {
    if (arithmeticOperator == "+") {
        return secondValue + firstValue;
    }
    else if (arithmeticOperator == "-") {
        return secondValue - firstValue;
    }
    else if (arithmeticOperator == "*") {
        return secondValue * firstValue;
    }
    else if (arithmeticOperator == "/") {
        return secondValue / firstValue;
    } else {
        return 0;
    }
}