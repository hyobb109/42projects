#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("hyobicho"), grade_(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name_(name), grade_(grade) {
  if (grade < 1) throw Bureaucrat::GradeTooHighException();
  if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
    : name_(b.name_), grade_(b.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
  if (this != &b) grade_ = b.grade_;
  return *this;
}

const std::string& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::increaseGrade() {
  if (grade_ == 1) throw Bureaucrat::GradeTooHighException();
  --grade_;
}

void Bureaucrat::decreaseGrade() {
  if (grade_ == 150) throw Bureaucrat::GradeTooLowException();
  ++grade_;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "🚨 등급이 너무 높습니다 (등급: 1 ~ 150) 🚨";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "🚨 등급이 너무 낮습니다 (등급: 1 ~ 150) 🚨";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ": " << b.getGrade() << "등급 관료";
  return os;
}
