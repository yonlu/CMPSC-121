#include <iostream>
#include <cstring>

using namespace std;

void question2() {
  char dog[] = "Fido";
  cout << strlen(dog) << endl;
}

void question3() {
  char string1[16] = "Have a ";
  char string2[9] = "nice day";
  strcat(string1, string2);
  cout << string1 << endl;
  cout << string2 << endl;
  return;
}

void question4() {
  char name[] = "Beethoven";
  int size = strlen(name) + 1;
  char composer[size];

  strcpy(composer, name);
  cout << composer << endl;
}

void question5() {
  char place[] = "The Windy City";
  char windy[] = "Windy";

  char* strPtr = nullptr;

  strPtr = strstr(place, windy);
  if (strPtr != nullptr) {
    cout << "Windy found." << endl;
  } else {
    cout << "Windy not found." << endl;
  }
  return;
}

int main() {
  question5();
  return 0;
}

