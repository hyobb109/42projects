#ifndef RRFORM_HPP
#define RRFORM_HPP

#include <cstdlib>

#include "AForm.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BASIC "\033[0m"

class RobotomyRequestForm : public AForm {
 private:
  std::string target_;

 public:
  RobotomyRequestForm();
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& form);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
  virtual void execute(Bureaucrat const& executor) const;
};

#endif