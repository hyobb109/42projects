#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& intern) { (void)intern; }

Intern& Intern::operator=(const Intern& intern) {
  (void)intern;
  return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
  static std::string form_list[] = {"Shrubbery Creation", "Robotomy Request",
                                    "Presidential Pardon"};
  int i = -1;
  while (++i < 3) {
    if (name == form_list[i]) {
      std::cout << "인턴이 " << name << " 문서를 작성했습니다" << std::endl;
      break;
    }
  }

  switch (i) {
    case SHRUBBERRY:
      return new ShrubberyCreationForm(target);
    case ROBOTOMY:
      return new RobotomyRequestForm(target);
    case PRESIDENTIAL:
      return new PresidentialPardonForm(target);
    default:
      std::cout << "🚨 존재하지 않는 문서입니다 🚨" << std::endl;
  }
  return 0;
}
