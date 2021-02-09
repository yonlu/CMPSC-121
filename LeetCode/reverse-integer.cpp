#include <iostream>

int reverse(int);

int reverse(int x) {
    std::string numberString = std::to_string(x);
    int length = numberString.size();
    std::reverse(numberString.begin(), numberString.end());
    
    try {
        int i = std::stoi(numberString);
        return numberString[length - 1] == '-' ? -1 * i : i;
    } catch(std::out_of_range &e) {
        return 0; 
    }
}

int main() {
  std::cout << reverse(123) << std::endl;
  std::cout << reverse(-123) << std::endl;
  std::cout << reverse(120) << std::endl;
  std::cout << reverse(0) << std::endl;

  return 0;
}
