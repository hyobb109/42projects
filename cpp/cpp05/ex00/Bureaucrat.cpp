#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increaseGrade() {}

void Bureaucrat::decreaseGrade() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
  return os;
}
