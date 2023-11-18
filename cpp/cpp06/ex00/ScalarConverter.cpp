#include "ScalarConverter.hpp"

// first detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other data typed
// display the results
// if conversion doesn't make any sencse or overflows => display impossible
void ScalarConverter::convert(std::string n) {
  int int_num;
  // double d_num;
  float f_num = 0.0f;
  std::stringstream ss(n);
  while (ss >> int_num) {
    std::cout << int_num << std::endl;
  }

  // std::cout << "char " << int_num << std::endl;
  // std::cout << "int: " << int_num << std::endl;
  // std::cout << "float: " << d_num << std::endl;
  std::cout << "double: " << f_num << 'f' << std::endl;
}
