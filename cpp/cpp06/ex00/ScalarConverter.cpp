#include "ScalarConverter.hpp"

// first detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other data typed
// display the results
// if conversion doesn't make any sencse or overflows => display impossible
void ScalarConverter::convert(std::string n) {
  std::stringstream ss(n);

  std::cout << "char: " << n << std::endl;
  std::cout << "int: " << n << std::endl;
  std::cout << "float: " << n << std::endl;
  std::cout << "double: " << n << std::endl;
}
