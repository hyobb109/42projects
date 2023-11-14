#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target_("Bear") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
    : AForm("Robotomy Request", 72, 45), target_(form.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& form) {
  if (this != &form) target_ = form.target_;
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!this->isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << "🤖 위잉위잉... 🤖" << std::endl;
  // TODO: 50% 확률 구현
  std::cout << GREEN << target_ << " robotomizing 성공!" << BASIC << std::endl;
  std::cout << RED << target_ << " robotomizing 실패.." << BASIC << std::endl;
}