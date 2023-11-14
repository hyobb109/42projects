#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target_("Home") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
    : AForm("Shrubbery Creation", 145, 137), target_(form.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& form) {
  if (this != &form) target_ = form.target_;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!this->isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  // TODO: Create a file <target>_shrubbery in the working directory, and writes
  // ASCII trees inside it
}