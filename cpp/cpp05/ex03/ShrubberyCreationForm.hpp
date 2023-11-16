#ifndef SCFORM_HPP
#define SCFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string target_;

 public:
  ShrubberyCreationForm();
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& form);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
  virtual void execute(Bureaucrat const& executor) const;
};

#endif