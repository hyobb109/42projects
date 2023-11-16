#ifndef PPFORM_HPP
#define PPFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target_;

 public:
  PresidentialPardonForm();
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& form);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
  virtual void execute(Bureaucrat const& executor) const;
};

#endif