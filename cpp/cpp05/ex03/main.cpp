#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  std::cout << "======인턴 일하는 중======" << std::endl;
  Intern bunny;
  AForm* shrubbery = bunny.makeForm("Shrubbery Creation", "house");
  if (!shrubbery) return 0;
  std::cout << *shrubbery << std::endl;
  AForm* robotomy = bunny.makeForm("Robotomy Request", "아톰");
  if (!robotomy) {
    delete shrubbery;
    return 0;
  }
  std::cout << *robotomy << std::endl;
  AForm* pardon = bunny.makeForm("Presidential Pardon", "포도");
  if (!pardon) {
    delete shrubbery;
    delete robotomy;
    return 0;
  }
  std::cout << *pardon << std::endl;
  AForm* hahaha = bunny.makeForm("hahaha", "target");
  if (!hahaha) {
    delete shrubbery;
    delete robotomy;
    delete pardon;
    return 0;
  }
  std::cout << *hahaha << std::endl;

  try {
    std::cout << "=======테스트=======" << std::endl;
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