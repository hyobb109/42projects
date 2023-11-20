#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

enum TYPE { CHAR, INT, FLOAT, DOUBLE };

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& s);
  ScalarConverter& operator=(const ScalarConverter& s);
  static void notANumber();
  static void detectType(std::string str);
  static void convertInt(const char* str);
  static void convertChar(const char* str);
  static void convertFloat(const char* str);
  static void convertDouble(const char* str);

 public:
  static void convert(std::string str);
};

#endif