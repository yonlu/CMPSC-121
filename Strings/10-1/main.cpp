#include <iostream>
#include <cctype>

using namespace std;

void checkPointOne();
void checkPointTwo();
void checkPointThree();
void checkPointFour();
void checkPointFive();

int main() {
    int selection;

    cout << "Please make a selection from the list below: " << endl;
    cout << "1: (Checkpoint 10.1)" << endl;
    cout << "2: (Checkpoint 10.2)" << endl;
    cout << "3: (Checkpoint 10.3)" << endl;
    cout << "4: (Checkpoint 10.4)" << endl;
    cout << "5: (Checkpoint 10.5)" << endl;
    cin >> selection;

    switch (selection) {
        case 1:
            checkPointOne();
            break;
        case 2:
            checkPointTwo();
            break;
        case 3:
            checkPointThree();
            break;
        case 4:
            checkPointFour();
            break;
        case 5:
            checkPointFive();
            break;
        default:
            break;
    }

    return 0;
}

void checkPointOne() {

    /* Write a short description of each of the following functions:
     *
     * isalpha
     * isalnum
     * isdigit
     * islower
     * isprint
     * ispunct
     * isupper
     * isspace
     * toupper
     * tolower
     */

    char character;
    cout << "Checkpoint 10.1" << endl;
    cout << "Enter a character: ";
    cin >> character;

    // isalpha => checks if a character is alphabetical
    if (isalpha(character))
        cout << character << " is alphabetical" << endl;

    // isalnum => check if a character is alphanumerical
    if (isalnum(character))
       cout << character << " is alphanumerical" << endl;

    // isdigit => checks if a character is a digit
    if (isdigit(character))
        cout << character << " is a digit" << endl;

    // islower => checks if a character is lowercase
    if (islower(character))
        cout << character << " is lowercase" << endl;

    // isprint => checks if a character is printable
    /*
     * List of non-printable characters:
     * Control codes (NUL, etc.)
     * tabs (\t)
     * whitespaces (\n, \v, \f, \r)
     * backspace (character DEL)
     */
    if (isprint(character))
        cout << character << " is printable" << endl;

    // is punct => checks if a character is a punctuation character
    /*
     * List of punctuations:
     * ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
     */
    if (ispunct(character))
        cout << character << " is a punctuation" << endl;

    // isupper => checks if a character is uppercase
    if (isupper(character))
        cout << character << " is uppercase" << endl;

    // isspace => checks if a character is a space
    // List of space characters: ' ', '\f', '\n', '\r', '\t', '\v'
    if (isspace(character))
        cout << character << " is a space" << endl;

    // toupper => returns the uppercase equivalent of that character (in int format);
    char upper = toupper(character); // Note that a casting happens here
    cout << character << " to uppercase has an ASCII value of: " << toupper(character) << endl;
    cout << character << " to uppercase has a character value of: " << upper << endl;

    // tolower => returns the lowercase equivalent of that character (in int format);
    char lower = tolower(character); // Note that a casting happens here.
    cout << character << " to lowercase has an ASCII value of: " << tolower(character) << endl;
    cout << character << " to lowercase has a character value of: " << lower << endl;
}

void checkPointTwo() {
    /*
     * Write an statement that will convert the contents of the char variable big
     * to lowercase. The converted value should be assigned to variable little;
     */

    cout << "Checkpoint 10.2" << endl;

    char big = 'A';
    char little = tolower(big);

    cout << "big has a value of " << big << endl;
    cout << "little has a value of " << little << endl;
}

void checkPointThree() {
    /*
     * Write an if statement that will display the word "digit" if the variable
     * ch contains a numeric digit. Otherwise, it should display "Not a digit."
     */

    cout << "Checkpoint 10.3" << endl;

    char ch;
    cout << "Please enter a character: ";
    cin >> ch;

    if (isdigit(ch))
        cout << "digit" << endl;
    else
        cout << "Not a digit." << endl;

};

void checkPointFour() {
    /*
     * What is the output of the following function?
     * cout << toupper(tolower('A'));
     */

    char ch;

    cout << "What is the output of the following function?" << endl;
    cout << "cout << toupper(tolower('A'));" << endl;
    cout << "Press any character to show the answer" << endl;
    cin >> ch;
    if (isprint(ch)) {
       cout << "The answer is: " << toupper(tolower('A')) << endl;
    }
}

void checkPointFive() {
    /*
     * Write a loop that asks the user
     * "Do you want to repeat the program or quit? (R/Q)"
     * The loop should repeat until the user has entered:
     * an R or a Q (either uppercase or lowercase).
     */

    char choice;
    do {
        cout << "Do you want to repeat the program or quit? (R/Q) ";
        cin >> choice;

        while(toupper(choice) != 'R' && toupper(choice) != 'Q') {
           cout << "Please enter R or Q: ";
           cin >> choice;
        }

    } while(toupper(choice) == 'R');
}