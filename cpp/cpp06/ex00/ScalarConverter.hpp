#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

enum { CHAR, INT, FLOAT, DOUBLE };
class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& s);
  ScalarConverter& operator=(const ScalarConverter& s);
  static void notANumber();
  static void infiniteNumber(const char* str);
  static bool convertChar(char c);
  static bool isPseudoLiteral(std::string str);
  static void printInt(double num);
  static void printChar(int num);
  static void convertNumber(const char* str, int precision, bool isFloat);

 public:
  static void convert(std::string str);
};

#endif