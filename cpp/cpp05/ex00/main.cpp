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
    Bureaucrat banana("바나나", 2);
    std::cout << banana << std::endl;
    banana.increaseGrade();
    banana.increaseGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat blueberry("블루베리", 149);
    std::cout << blueberry << std::endl;
    blueberry.decreaseGrade();
    blueberry.decreaseGrade();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}