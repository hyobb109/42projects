#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  std::cout << "======문서 목록======" << std::endl;

  AForm* shrubbery = new ShrubberyCreationForm("house");
  std::cout << *shrubbery << std::endl;
  AForm* robotomy = new RobotomyRequestForm("아톰");
  std::cout << *robotomy << std::endl;
  AForm* pardon = new PresidentialPardonForm("포도");
  std::cout << *pardon << std::endl;

  std::cout << "=======테스트=======" << std::endl;
  try {
    Bureaucrat banana("바나나", 1);
    std::cout << banana << std::endl;
    Bureaucrat blueberry("블루베리", 20);
    std::cout << blueberry << std::endl;
    Bureaucrat apple("사과", 130);
    std::cout << apple << std::endl;

    std::cout << "==================" << std::endl;
    banana.executeForm(*pardon);
    std::cout << "====서명 중...====" << std::endl;
    blueberry.signForm(*pardon);
    blueberry.signForm(*shrubbery);
    blueberry.signForm(*robotomy);
    std::cout << "====집행 중...=====" << std::endl;
    apple.executeForm(*shrubbery);
    blueberry.executeForm(*robotomy);
    blueberry.executeForm(*pardon);
    banana.executeForm(*pardon);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  delete shrubbery;
  delete robotomy;
  delete pardon;

  return 0;
}