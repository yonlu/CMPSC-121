#include <iostream>

struct Point {
  double x;
  double y;
};

struct Slope {
  double m;
  double b;
};

// calculates the slope of points A and B
Slope getSlope(Point A, Point B);

// determines whether points A, B, and C lie on a single straight line
bool inLine(Point A, Point B, Point C);

// calculates the midpoint of points A and B
Point midpoint(Point A, Point B);

int main() {
  Point pointA;
  Point pointB;
  Point pointC;

  // Points
  std::cout << "Enter A's (x, y) coordinates: ";
  std::cin >> pointA.x;
  std::cin >> pointA.y;

  std::cout << "Enter B's (x, y) coordinates: ";
  std::cin >> pointB.x;
  std::cin >> pointB.y;

  std::cout << "Enter C's (x, y) coordinates: ";
  std::cin >> pointC.x;
  std::cin >> pointC.y;

  // Midpoints
  Point midpointAandB = midpoint(pointA, pointB);
  std::cout << "The midpoint of A and B: ";
  std::cout << "(" << midpointAandB.x << ", " << midpointAandB.y << ")" << std::endl;

  Point midpointBandC = midpoint(pointB, pointC);
  std::cout << "The midpoint of B and C: ";
  std::cout << "(" << midpointBandC.x << ", " << midpointBandC.y << ")" << std::endl;

  Point midpointCandA = midpoint(pointC, pointA);
  std::cout << "The midpoint of C and A: ";
  std::cout << "(" << midpointCandA.x << ", " << midpointCandA.y << ")" << std::endl;

  // Slopes
  Slope slopeAtoB = getSlope(pointA, pointB);
  slopeAtoB.b = midpointAandB.y - slopeAtoB.m * midpointAandB.x;
  std::cout << "The slope of A and B: y =  " << slopeAtoB.m << " * x + " << slopeAtoB.b << std::endl;

  Slope slopeBtoC = getSlope(pointB, pointC);
  slopeBtoC.b = midpointBandC.y - slopeBtoC.m * midpointBandC.x;
  std::cout << "The slope of A and B: y =  " << slopeBtoC.m << " * x + " << slopeBtoC.b << std::endl;

  Slope slopeCtoA = getSlope(pointC, pointA);
  slopeCtoA.b = midpointCandA.y - slopeCtoA.m * midpointCandA.x;
  std::cout << "The slope of A and B: y =  " << slopeCtoA.m << " * x + " << slopeCtoA.b << std::endl;


  // Check if points are on the same line.
  bool belongsSingleLine = inLine(pointA, pointB, pointC);
  if (belongsSingleLine) {
    std::cout << "A, B and C belong to a single line." << std::endl;
  } else {
    std::cout << "A, B and C DO NOT belong to a single line." << std::endl;
  }

  return 0;
}


Point midpoint(Point A, Point B) {
  Point midpoint;
  midpoint.x = ((A.x + B.x)/2);
  midpoint.y = ((A.y + B.y)/2);
  return midpoint;
}

Slope getSlope(Point A, Point B) {
  Slope slope;
  slope.m = (B.y - A.y)/(B.x - A.x);
  return slope;
}

bool inLine(Point A, Point B, Point C) {
  return ((B.y - A.y)/(B.x - A.x) == (C.y - A.y)/(C.x - A.x));
}