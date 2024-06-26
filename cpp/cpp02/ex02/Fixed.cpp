#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
  // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) : fixedPoint(num << bits) {
  // std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num)
    : fixedPoint(static_cast<int>(roundf(num * (1 << bits)))) {
  // std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) : fixedPoint(fixed.fixedPoint) {
  // std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
  // std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& fixed) {
  // std::cout << "Copy assignment operator called\n";
  if (this != &fixed) fixedPoint = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called\n";
  return fixedPoint;
}

void Fixed::setRawBits(int const raw) { fixedPoint = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(fixedPoint) / (1 << bits);
}

int Fixed::toInt(void) const { return fixedPoint / (1 << bits); }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

// ex02
bool Fixed::operator>(const Fixed& fixed) const {
  return fixedPoint > fixed.fixedPoint ? true : false;
}
bool Fixed::operator<(const Fixed& fixed) const {
  return fixedPoint < fixed.fixedPoint ? true : false;
}
bool Fixed::operator>=(const Fixed& fixed) const {
  return fixedPoint >= fixed.fixedPoint ? true : false;
}
bool Fixed::operator<=(const Fixed& fixed) const {
  return fixedPoint <= fixed.fixedPoint ? true : false;
}

bool Fixed::operator==(const Fixed& fixed) const {
  return fixedPoint == fixed.fixedPoint ? true : false;
}

bool Fixed::operator!=(const Fixed& fixed) const {
  return fixedPoint != fixed.fixedPoint ? true : false;
}

Fixed Fixed::operator+(const Fixed& fixed) const {
  Fixed res(static_cast<float>(fixedPoint + fixed.fixedPoint) / (1 << bits));
  return res;
}

Fixed Fixed::operator-(const Fixed& fixed) const {
  Fixed res(static_cast<float>(fixedPoint - fixed.fixedPoint) / (1 << bits));
  return res;
}

Fixed Fixed::operator*(const Fixed& fixed) const {
  int tmp = fixedPoint * fixed.fixedPoint / (1 << bits);
  Fixed res(static_cast<float>(tmp) / (1 << bits));
  return res;
}

Fixed Fixed::operator/(const Fixed& fixed) const {
  int tmp = fixedPoint * (1 << bits) / fixed.fixedPoint;
  Fixed res(static_cast<float>(tmp) / (1 << bits));
  return res;
}

Fixed& Fixed::operator++() {
  ++fixedPoint;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed res(*this);
  fixedPoint++;
  return res;
}

Fixed& Fixed::operator--() {
  --fixedPoint;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed res(*this);
  fixedPoint--;
  return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return a > b ? b : a; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return a > b ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) { return a < b ? a : a; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return a < b ? b : a;
}
