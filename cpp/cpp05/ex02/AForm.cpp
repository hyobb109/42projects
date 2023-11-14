#include "AForm.hpp"

AForm::AForm()
    : name_("default"), signed_(false), sign_grade_(1), execute_grade_(1) {}

AForm::AForm(const std::string name, const int sign_grade,
             const int execute_grade)
    : name_(name),
      signed_(false),
      sign_grade_(sign_grade),
      execute_grade_(execute_grade) {
  if (sign_grade_ < 1 || execute_grade_ < 1)
    throw AForm::GradeTooHighException();
  if (sign_grade_ > 150 || execute_grade_ > 150)
    throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& f)
    : name_(f.name_),
      signed_(f.signed_),
      sign_grade_(f.sign_grade_),
      execute_grade_(f.execute_grade_) {}

AForm& AForm::operator=(const AForm& f) {
  if (this != &f) signed_ = f.signed_;
  return *this;
}

const std::string& AForm::getName() const { return name_; }

bool AForm::isSigned() const { return signed_; }

const int& AForm::getGradeToSign() const { return sign_grade_; }

const int& AForm::getGradeToExecute() const { return execute_grade_; }

void AForm::beSigned(const Bureaucrat& b) {
  if (signed_) throw AForm::AlreadySignedException();
  if (b.getGrade() > sign_grade_) throw AForm::GradeTooLowException();
  signed_ = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "🚨 등급이 너무 높습니다 🚨";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "🚨 등급이 너무 낮습니다 🚨";
}

const char* AForm::AlreadySignedException::what() const throw() {
  return "🚨 이미 서명된 문서입니다 🚨";
}

const char* AForm::NotSignedException::what() const throw() {
  return "🚨 서명되지 않은 문서입니다 🚨";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
  std::string form_status;
  f.isSigned() ? form_status = "(서명✅)" : form_status = "(서명❎)";
  os << "📜 " << f.getName() << form_status << " 📜\n";
  os << "서명 가능 등급: " << f.getGradeToSign() << "\n";
  os << "집행 가능 등급: " << f.getGradeToExecute();
  return os;
}
