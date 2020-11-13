#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char arr[] = "Four score and seven years ago";
    char *strPtr = nullptr;

    cout << arr << endl;
    cout << *(arr + 3) << endl;
    strPtr = strstr(arr, "seven");
}
