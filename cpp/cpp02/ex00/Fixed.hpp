#include <iostream>

class Fixed {
 private:
  int fixedPoint;
  static const int bits = 8;

 public:
  Fixed(int fixedPoint);                 // default constructor
  Fixed(const Fixed& fixed);             // copy constructor
  Fixed& operator=(const Fixed& fixed);  // copy assignment operator overload
  ~Fixed();                              // destructor
  int getRawBits(void) const;
  void setRawBits(int const raw);
};