#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& s);
  ScalarConverter& operator=(const ScalarConverter& s);
  static void notANumber();
  static bool isPseudoLiteral(std::string str);
  static void convertInt(const char* str);
  static void convertChar(const char* str);
  static void convertFloat(const char* str, int precision);
  static void convertDouble(const char* str, int precision);

 public:
  static void convert(std::string str);
};

#endif