#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string name_;
  bool signed_;
  const int sign_grade_;
  const int execute_grade_;
  Form& operator=(const Form& f);

 public:
  Form();
  Form(const std::string name, const int sign_grade, const int execute_grade);
  ~Form();
  Form(const Form& f);
  const std::string& getName() const;
  bool isSigned() const;
  const int& getGradeToSign() const;
  const int& getGradeToExecute() const;
  void beSigned(const Bureaucrat& b);
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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
