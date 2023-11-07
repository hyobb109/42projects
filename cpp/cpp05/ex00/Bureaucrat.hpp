#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
 private:
  const std::string name;
  int grade;

 public:
  Bureaucrat(const std::string name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& b);
  Bureaucrat& operator=(const Bureaucrat& b);
  std::string getName() const;
  int getGrade() const;
  void increaseGrade();
  void decreaseGrade();
  class GradeTooHighException : public std::exception {};
  class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif