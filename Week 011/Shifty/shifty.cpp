#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int* shiftAdd(int *oldArr, int oldArrSize, int newValue);
void generateSummary(int* arr, int size);

int main() {
    int count = 0;
    int value;
    int* arr = nullptr;

    do {
        cout << "Please input a value or -1 to end: ";
        cin >> value;
        if(value != -1) {
            arr = shiftAdd(arr, count, value);
            count++;
        }
    } while(value != -1);

    generateSummary(arr, count);

    delete [] arr;

    return 0;
}
int* shiftAdd(int *oldArr, int oldArrSize, int newValue) {
    /*
     * Functionality:
     * the function shiftAdd (described below)
     * must be called to resize the array
     * and return a new array with the value the user
     * just entered at the index position such that the new array
     * is sorted in ascending (or descending) order.
     *
     * Definition:
     * Takes in the old array, the size of the old array, and the new value to add.
     * The function should create the new array using dynamic allocation,
     * put the newValue at the position such that the new array is sorted (ascending or descending)
     * while filling in the values from the old array.
     * The program should then deallocate the old array and return
     * the pointer to the new array.
     */

    // Dynamically allocate an array large enough to hold
    // oldArraySize+1 elements.
    int size = oldArrSize+1;
    int *arr;
    arr = new int[size];

    // Store newValue at arr[0].
    *arr = newValue;

    // Store all the remaining values into new array.
    for(int i = 0; i < oldArrSize; i++) {
        *(arr + i + 1) = *(oldArr + i);
    }

    // Deallocate unused memory
    delete [] oldArr;

    // Sort the array in ascending order.
    bool sorted = false;
    while(!sorted) {
       sorted = true;
       for (int i = 0; i < size - 1; i++) {
           if (arr[i] > arr[i+1]) {
               int tmp = arr[i];
               arr[i] = arr[i+1];
               arr[i+1] = tmp;
               sorted = false;
           }
       }
    }

   return arr;
}

void generateSummary(int* arr, int size) {
    if (size % 2 == 0) {
      int middleOne = (size/2)-1;
      int middleTwo = (size/2);
      cout << fixed << showpoint;
      cout << setprecision(2);
      cout << "The median is: "<< ((static_cast<double>(arr[middleOne]) + arr[middleTwo])/2)<< endl;
    } else {
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << "The median is: " << static_cast<double>(arr[(size/2)]) << endl;
    }

    double mean = 0.0;
    for (int i = 0; i < size; i++) {
        mean += arr[i];
    }
    mean /= static_cast<double>(size);


    int repeat = -1;
    for (int i = 0; i < size -1; i++) {
        if (arr[i] == arr[i+1]) {
            repeat = arr[i];
        }
    }

    if (repeat != -1) {
        cout << "The mode is " << repeat << endl;
    } else {
        cout << "The mode is none" << endl;
    }
    cout << "The mean is " << mean << endl;
}
