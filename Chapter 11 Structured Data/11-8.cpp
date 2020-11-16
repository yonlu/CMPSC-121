// This program demonstrates a function that uses a
// pointer to a structure variable as a parameter.  
#include <iostream>
#include <string>
#include <iomanip>

struct Student {
  std::string name;
  int idNum;
  int creditHours;
  double gpa;
};

void getData(Student*);

int main() {
  Student freshman;

  std::cout << "Enter the following student data:\n";
  getData(&freshman);
  std::cout << "\nHere is the student data you entered:\n";

  std::cout << std::setprecision(3);
  std::cout << "Name: " << freshman.name << std::endl;
  std::cout << "ID Number: " << freshman.idNum << std::endl;
  std::cout << "Credit hours: " << freshman.creditHours << std::endl;
  std::cout << "GPA: " << freshman.gpa << std::endl;

  return 0;

}

void getData(Student *s) {
  std::cout << "Student name: ";
  getline(std::cin, s->name);

  std::cout << "Student ID Number: ";
  std::cin >> s->idNum;

  std::cout << "Credit hours enrolled: ";
  std::cin >> s->creditHours;

  std::cout << "Current GPA: ";
  std::cin >> s->gpa;
}