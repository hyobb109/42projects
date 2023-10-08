#include <iostream>

class Fixed {
 private:
  int fixedPoint;
  static const int bits = 8;

 public:
  Fixed();                               // default constructor
  Fixed(const Fixed& fixed);             // copy constructor
  ~Fixed();                              // destructor
  Fixed& operator=(const Fixed& fixed);  // copy assignment operator overload
  int getRawBits() const;  // returns the raw value of the fixed-point value
  void setRawBits(
      int const raw);  // sets the raw value of the fixed-point number
};