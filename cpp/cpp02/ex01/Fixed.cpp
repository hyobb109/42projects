#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << "Default constructor called\n"; }

// It converts the parameter to the corresponding fixed-point value.
Fixed::Fixed(const int num) : fixedPoint(num) {
  std::cout << "Int constructor called\n";
  fixedPoint = num;
}

// It converts the parameter to the corresponding fixed-point value.
Fixed::Fixed(const float num) : fixedPoint(num) {
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called\n";
  fixedPoint = fixed.fixedPoint;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed& Fixed::operator=(const Fixed& fixed) {
  std::cout << "Copy assignment operator called\n";
  fixedPoint = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return fixedPoint;
}

void Fixed::setRawBits(int const raw) { fixedPoint = raw; }

// converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
  float n;
  std::cout << "Float constructor called\n";
  return n;
}

// converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
  int n;
  std::cout << "Int constructor called\n";
  return n;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
