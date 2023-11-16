#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target_("hyobicho") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& form)
    : AForm("Presidential Pardon", 25, 5), target_(form.target_) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& form) {
  if (this != &form) target_ = form.target_;
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!this->isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << "Zaphod Beeblebrox가 " << target_ << "(을)를 사면했습니다."
            << std::endl;
}