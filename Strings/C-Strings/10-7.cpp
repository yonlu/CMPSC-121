#include <iostream>
#include <string>

int main() {
  const int LENGTH = 40;
  char firstString[LENGTH];
  char secondString[LENGTH];

  std::cout << "Enter a string: ";
  std::cin.getline(firstString, LENGTH);

  int i = strlen(firstString) - 1;

  int j = 0;
  while (i >= 0) {
    secondString[j] = firstString[i];
    j++;
    i--;
  }

  if (strcmp(firstString, secondString) == 0) {
    std::cout << "It's a palindrome";
  } else {
    std::cout << "Not a palindrome.\n";
  }

  return 0;
}
