#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  std::cout << "=======테스트 1=======" << std::endl;
  try {
    Form apple("사과", 0, 100);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=======테스트 2=======" << std::endl;
  try {
    Form apple("사과", 100, 151);
    std::cout << apple << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=======테스트 3=======" << std::endl;
  try {
    Bureaucrat banana("바나나", 1);
    std::cout << banana << std::endl;
    Form icecream("아이스크림", 10, 10);
    std::cout << icecream << std::endl;
    icecream.beSigned(banana);
    std::cout << icecream << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "=======테스트 4=======" << std::endl;
  try {
    Bureaucrat blueberry("블루베리", 150);
    std::cout << blueberry << std::endl;
    Form chocolate("초콜릿", 100, 100);
    std::cout << chocolate << std::endl;
    chocolate.beSigned(blueberry);
    std::cout << chocolate << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}