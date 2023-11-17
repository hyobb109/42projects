#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& s);
  ScalarConverter& operator=(const ScalarConverter& s);

 public:
  static void convert(std::string n);
};

#endif