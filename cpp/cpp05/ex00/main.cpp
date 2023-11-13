#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat apple("사과", 0);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat apple("사과", 151);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat banana("바나나", 1);
    std::cout << banana << std::endl;
    banana.increaseGrade();
    std::cout << banana << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat blueberry("블루베리", 150);
    std::cout << blueberry << std::endl;
    blueberry.decreaseGrade();
    std::cout << blueberry << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}