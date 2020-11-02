#include <iostream>

using namespace std;

int main() {
    /*
     * Quiz Arrays and Vectors
     * 7.1: Define the Following arrays:
     * a) empNums, a 100-element array of ints
     * b) payRates, a 25-element array of floats
     * c) miles, a 14-element array of longs
     * d) cityName, a 26-element array of string objects
     * e) lightYears, a 1000-element array of doubles
     */

    int empNums[100];
    float payRates[25];
    long miles[14];
    string cityName[26];
    double lightYears[1000];

    /*
     * 7.2: What's wrong with the following array definitions?
     * a) int readings[-1]
     * b) float measurements[4.5]
     * c) int size;
     * string names[size];
     *
     * a) the array's size can not be negative.
     * b) the array's size can not be a floating point value.
     * c) variable size is not initialized, so we can't not use to as a value for the array's size.
     */

    /*
     * 7.3: What would the valid subscript values be in a 4-element array of doubles?
     * 0, 1, 2, 3
     */

    /*
     * 7.4: What is the difference between an array's size declarator and a subscript?
     * Array's size declarator defines how many element can be stored on the array,
     * a subscript is used to access the value stored in a particular location of the array
     */

    /*
     * 7.5: What is "arrays bound checking"? Does C++ perform it?
     * It is a safeguard mechanism to prevent unsafe memory access. C++ does not perform arrays bound checking.
     */

    /*
     * 7.6: What is the output of the following code?
     *
     * int values[5], count;
     * for (count = 0; count < 5; count++) {
     *     values[count] = count + 1;
     * }
     *
     * for (count = 0; count < 5; count++) {
     *     cout << values[count] << endl;
     * }
     *
     * values[count] = 0+1, 1+1, 2+1, 3+1, 4+1
     * 1, 2, 3, 4, 5
     *
     * 1
     * 2
     * 3
     * 4
     * 5
     */

    /*
     * 7.7: The following skeleton contains a 20-element array of ints called fish.
     * When completed, the program should ask how many fish were caught by fishermen 1 through 20,
     * and store this data in the array. Complete the program.
     */

//    const int NUM_FISH = 20;
//    int fish[NUM_FISH];
//    // You must finish this program. It should ask how many were caught by fishermen 1-20,
//    // and store this data in array fish;
//
//    for (int i = 0; i < NUM_FISH; i++) {
//       cout << "How many fish did fisherman " << i+1 << " caught?";
//       cin >> fish[i];
//    }
//
//    for (int f : fish) {
//        cout << f << endl;
//    }

    /*
     * 7.8: Define the following arrays:
     * a) ages, a 10-element array of ints initialized with the values 5, 7, 9, 14, 15, 17, 18, 19, 21 and 23.
     * b) temps, a 7-element array of floats initialized with the values 14.7, 16.3, 18.43, 21.09, 17.9, 18.76, and 26.7.
     * c) alpha, an 8-element array of chars initialized with the values 'J', 'B', 'L', 'A', '*', '$', 'H' and 'M'.
     */

//    int ages[] = {5, 7, 9, 14, 15, 17, 18, 19, 21, 23};
//    float temps[] = { 14.7, 16.3, 18.43, 21.09, 17.9, 18.76, 26.7};
//    char alpha[] = { 'J', 'B', 'L', 'A', '*', '$', 'H', 'M'};

    /*
     * 7.9: Is each of the following a valid or invalid array definition?
     * (If definition is invalid, explain why.)
     *
     * a) int numbers[10] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 1};
     * b) int matrix[5] = {1, 2, 3, 4, 5, 6, 7};
     * c) double radii[10] = {3.2, 4.7};
     * d) int tables[7] = {2, , , 27, , 45, 39};
     * e) char codes[] = {'A', 'X', '1', '2', 's'};
     * f) int blanks[];
     *
     * a) valid
     * b) not valid, excess element in array initializer.
     * c) valid
     * d) not valid, array initialization can not skip values
     * e) valid
     * f) not valid, the array needs a explicit size if not using initialization.
     */

    return 0;

}