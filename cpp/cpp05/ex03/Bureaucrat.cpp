#include "Bureaucrat.hpp"

#include "AForm.hpp"

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
  std::cout << *this << " => " << --grade_ << "등급 관료" << std::endl;
}

void Bureaucrat::decreaseGrade() {
  if (grade_ == 150) throw Bureaucrat::GradeTooLowException();
  std::cout << *this << " => " << ++grade_ << "등급 관료" << std::endl;
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

// ex01
void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << grade_ << "등급 관료 " << name_ << "(이)가 " << form.getName()
              << " 문서에 서명했습니다📝" << std::endl;

  } catch (std::exception& e) {
    std::cout << name_ << "(은)는 " << form.getName()
              << " 문서에 서명할 수 없습니다. (사유: " << e.what() << ")"
              << std::endl;
  }
}

// ex02
void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
    std::cout << grade_ << "등급 관료 " << name_ << "(이)가 " << form.getName()
              << " 문서를 집행했습니다📢" << std::endl;
  } catch (std::exception& e) {
    std::cout << name_ << "(은)는 " << form.getName()
              << " 문서를 집행할 수 없습니다. (사유: " << e.what() << ")"
              << std::endl;
    return;
  }
}
