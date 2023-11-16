#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
 private:
  const std::string name_;
  bool signed_;
  const int sign_grade_;
  const int execute_grade_;
  AForm& operator=(const AForm& f);

 public:
  AForm();
  AForm(const std::string name, const int sign_grade, const int execute_grade);
  virtual ~AForm();
  AForm(const AForm& f);
  const std::string& getName() const;
  bool isSigned() const;
  const int& getGradeToSign() const;
  const int& getGradeToExecute() const;
  void beSigned(const Bureaucrat& b);
  virtual void execute(Bureaucrat const& executor) const = 0;
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class AlreadySignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class NotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
