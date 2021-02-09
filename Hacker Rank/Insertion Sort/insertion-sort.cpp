#include <iostream>

using namespace std;

int main() {
    int numbers[] = {8, 2, 4, 1, 3};
    int current;

    /*
     * Input numbers = 8, 2, 4, 1, 3
     * Expected output = 1, 2, 3, 4, 8
     *
     * current = numbers[0] => 8
     * j = 0 - 1; => -1
     *
     * -1 >= 0 && numbers[-1] > current ? => False, and it will also short circuit, so out of bounds index is not checked.
     *
     * numbers[-1 + 1] = 8; => numbers[0] = 8;
     *
     * current = numbers[1] => 2
     * j = 1 - 1; => 0
     *
     * 0 >= 0 && numbers[0] > current ? 0 >= 0? True && 8 > 2? True
     *  numbers[0 + 1] = numbers[0]; => numbers[1] = numbers[0]
     *  Current array: 8, 8, 4, 1, 3
     *  j--; => -1
     *
     *  numbers[-1 + 1] = 2 => current[0] = 2
     *  Current array: 2, 8, 4, 1, 3
     *
     */

    for (int i = 0; i < 5; i++) {
        current = numbers[i];
        int j = i - 1;
        while(j >= 0 && numbers[j] > current) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = current;
    }

    for (int &number : numbers) {
        cout << number << " ";
    }

    return 0;
}
