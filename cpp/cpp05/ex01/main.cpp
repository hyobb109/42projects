#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat apple("Apple", 0);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat apple("Apple", 151);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat banana("Banana", 1);
    std::cout << banana << std::endl;
    banana.increaseGrade();
    std::cout << banana << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat blueberry("Blueberry", 150);
    std::cout << blueberry << std::endl;
    blueberry.decreaseGrade();
    std::cout << blueberry << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}