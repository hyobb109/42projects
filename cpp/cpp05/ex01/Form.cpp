#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : name_("default"), signed_(false), sign_grade_(1), execute_grade_(1) {}

Form::Form(const std::string name, const int sign_grade,
           const int execute_grade)
    : name_(name),
      signed_(false),
      sign_grade_(sign_grade),
      execute_grade_(execute_grade) {
  if (sign_grade_ < 1 || execute_grade_ < 1)
    throw Form::GradeTooHighException();
  if (sign_grade_ > 150 || execute_grade_ > 150)
    throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& f)
    : name_(f.name_),
      signed_(f.signed_),
      sign_grade_(f.sign_grade_),
      execute_grade_(f.execute_grade_) {}

Form& Form::operator=(const Form& f) {
  if (this != &f) signed_ = f.signed_;
  return *this;
}

const std::string& Form::getName() const { return name_; }

bool Form::isSigned() const { return signed_; }

const int& Form::getGradeToSign() const { return sign_grade_; }

const int& Form::getGradeToExecute() const { return execute_grade_; }

void Form::beSigned(const Bureaucrat& b) {
  if (b.getGrade() > sign_grade_) {
    b.signForm(*this);
    throw Form::GradeTooLowException();
  }
  signed_ = true;
  b.signForm(*this);
}

const char* Form::GradeTooHighException::what() const throw() {
  return "🚨 등급이 너무 높습니다 🚨";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "🚨 등급이 너무 낮습니다 🚨";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  std::string form_status;
  f.isSigned() ? form_status = "(서명✅)" : form_status = "(서명❎)";
  os << "📜 " << f.getName() << form_status << " 📜\n";
  os << "서명 가능 등급: " << f.getGradeToSign() << "\n";
  os << "집행 가능 등급: " << f.getGradeToExecute();
  return os;
}
