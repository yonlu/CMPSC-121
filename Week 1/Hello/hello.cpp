// using a preprocessor directive, include the iostream library
// which contains what we need to print to the terminal
#include <iostream>

// so we do not have to put std:: prior to each cout and endl,
// indicate we are using this namespace to the C++ compiler
using namespace std;

// the main function of our program
int main() {

   // prints the text "Hello, World!" to the command line
   cout << "Hello, World!" << endl;

   // return the value 0 to the operating system
   // indicating our program finished normally
   return 0;
}