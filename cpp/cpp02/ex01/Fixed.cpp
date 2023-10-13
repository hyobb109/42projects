#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << "Default constructor called\n"; }

// It converts the parameter to the corresponding fixed-point value.
Fixed::Fixed(const int num) : fixedPoint(num << bits) {
  std::cout << "Int constructor called\n";
}

// It converts the parameter to the corresponding fixed-point value.
Fixed::Fixed(const float num) : fixedPoint(roundf(num * (1 << bits))) {
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) : fixedPoint(fixed.fixedPoint) {
  std::cout << "Copy constructor called\n";
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
  return static_cast<float>(fixedPoint) / (1 << bits);
}

// converts the fixed-point value to an integer value
int Fixed::toInt(void) const { return fixedPoint / (1 << bits); }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
