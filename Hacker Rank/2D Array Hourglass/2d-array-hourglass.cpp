#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<vector<int>> arr {
        {-9, -9, -9,  1, 1, 1},
        {0, -9,  0,  4, 3, 2},
        {-9, -9, -9,  1, 2, 3},
        {0,  0,  8,  6, 6, 0},
        {0,  0,  0, -2, 0, 0},
        {0,  0,  1,  2, 4, 0},
    };

    vector<int> hourglass(16, 0);

    int sum = 0;

    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                sum += arr[i][j];
                sum += arr[i][j+1];
                sum += arr[i][j+2];
                sum += arr[i+1][j+1];
                sum += arr[i+2][j];
                sum += arr[i+2][j+1];
                sum += arr[i+2][j+2];
                hourglass.push_back(sum);
                sum = 0;
        }
    }

    sort(hourglass.begin(), hourglass.end());

    cout << hourglass[hourglass.size()-1] << endl;

    return 0;
}
