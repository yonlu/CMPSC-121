#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = 3.14159;

struct Circle {
  double radius;
  double diameter;
  double area;
};

Circle getInfo();

int main() {
  Circle c;

  c = getInfo();

  c.area = PI * pow(c.radius, 2.0);


  std::cout << "The radius and area of the circle are:\n";
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Radius: " << c.radius << std::endl;
  std::cout << "Area: " << c.area << std::endl;

  return 0;
}

Circle getInfo() {
  Circle tempCircle;

  std::cout << "Enter the diameter of a circle: ";
  std::cin >> tempCircle.diameter;
  tempCircle.radius = tempCircle.diameter / 2.0;

  return tempCircle;
}