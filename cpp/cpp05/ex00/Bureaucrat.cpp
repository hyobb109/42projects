#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("hyobicho"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name(name), grade(grade) {
  if (grade < 1) throw Bureaucrat::GradeTooHighException();
  if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name), grade(b.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
  grade = b.grade;
  return *this;
}

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increaseGrade() {
  if (grade == 1) throw Bureaucrat::GradeTooHighException();
  --grade;
}

void Bureaucrat::decreaseGrade() {
  if (grade == 150) throw Bureaucrat::GradeTooLowException();
  ++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "🚨 Grade Too High (Grade: 1 ~ 150) 🚨";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "🚨 Grade Too Low (Grade: 1 ~ 150) 🚨";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
