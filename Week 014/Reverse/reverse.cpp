#include <iostream>
#include <string>
#include <cctype>

void reverseString(std::string, int);

int main() {
    std::string userInput;
    char choice;

    do {
        std::cout << "Please enter a string: ";
        std::getline(std::cin, userInput);

        std::cout << "The reverse string is: ";
        reverseString(userInput, userInput.length());

        std::cout << "\nEnter another string? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore();

        while (toupper(choice) != 'Y' && toupper(choice) != 'N') {
            std::cout << "Please enter Y for yes or N for no: ";
            std::cin >> choice;
            std::cin.ignore();
        }
    } while(toupper(choice)== 'Y');

    return 0;
}

void reverseString(std::string phrase, int numberOfCharacters) {
    if (numberOfCharacters == 0) {
        return;
    }
    std::cout << phrase[numberOfCharacters - 1];
    phrase.pop_back();
    reverseString(phrase, phrase.length());
}
