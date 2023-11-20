#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) { (void)s; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s) {
  (void)s;
  return *this;
}

void ScalarConverter::notANumber() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}

void ScalarConverter::detectType(std::string str) {
  std::size_t found = str.find_first_not_of("0123456789");
  // digit 으로만 이루어져 있으면 int or char
  if (found == std::string::npos) {
    convertInt(str.c_str());
  } else if (str[found] == '.') {
    std::cout << "* " << str.substr(found + 1) << std::endl;
  }
}

void ScalarConverter::convertInt(const char* str) {
  std::cout << str << std::endl;
}

// void ScalarConverter::convertChar(const char* str) {}

// void ScalarConverter::convertFloat(const char* str) {}

// void ScalarConverter::convertDouble(const char* str) {}

// convert it from string to its actual type
// convert it explicitly to the three other data typed
// display the results
// if conversion doesn't make any sencse or overflows => display impossible
void ScalarConverter::convert(std::string str) {
  char** endptr = NULL;
  double d_num = 0;
  // int decimal = 0;

  // first detect the type of the literal passed as parameter
  detectType(str);
  if (str.find_first_of('f') == str.length() - 1) {
    d_num = atof(str.c_str());
    std::cout << std::fixed << std::setprecision(4) << "fnum: " << d_num
              << std::endl;
  } else {
    d_num = strtod(str.c_str(), endptr);
    std::cout << std::fixed << std::setprecision(4) << "num: " << d_num
              << std::endl;
  }
  std::cout << endptr << "\n";
  if (endptr) {
    notANumber();
    return;
  }
  // std::cout << "char " << int_num << std::endl;
  // std::cout << "int: " << int_num << std::endl;
  // std::cout << "float: " << d_num << std::endl;
  // std::cout << "double: " << f_num << 'f' << std::endl;
}
