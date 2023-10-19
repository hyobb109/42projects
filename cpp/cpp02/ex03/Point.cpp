#include "Point.hpp"

Point::Point() : x(0), y(0) { std::cout << "Default Constructor called\n"; }

Point::~Point() { std::cout << "Destructor called\n"; }

Point::Point(const Point& p) : x(p.x), y(p.y) {
  std::cout << "Copy Constructor called\n";
}
Point& Point::operator=(const Point& p) {
  std::cout << "Copy assignment operator called\n";
  this->~Point();
  Point* ptr = new Point(p);
  return *ptr;
}