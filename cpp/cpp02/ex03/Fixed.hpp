#include <cmath>
#include <iostream>

class Fixed {
 private:
  int fixedPoint;
  static const int bits = 8;

 public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  Fixed(const Fixed& fixed);
  ~Fixed();
  Fixed& operator=(const Fixed& fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // comparison operators
  bool operator>(const Fixed& fixed) const;
  bool operator<(const Fixed& fixed) const;
  bool operator>=(const Fixed& fixed) const;
  bool operator<=(const Fixed& fixed) const;
  bool operator==(const Fixed& fixed) const;
  bool operator!=(const Fixed& fixed) const;

  // arithmetic operators
  Fixed operator+(const Fixed& fixed) const;
  Fixed operator-(const Fixed& fixed) const;
  Fixed operator*(const Fixed& fixed) const;
  Fixed operator/(const Fixed& fixed) const;

  // increment/decrement operators
  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& min(Fixed& fixed1, Fixed& fixed2);
  static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
  static Fixed& max(Fixed& fixed1, Fixed& fixed2);
  static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);