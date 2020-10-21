#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> myVector {1, 2, 3, 4, 10, 11};

   for (int val : myVector) {
       cout << val << endl;
   }

   return 0;
}