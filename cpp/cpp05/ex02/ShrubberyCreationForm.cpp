#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target_("Home") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
    : AForm("Shrubbery Creation", 145, 137), target_(form.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& form) {
  if (this != &form) target_ = form.target_;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!this->isSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::string tmp = target_ + "_shrubbery";
  std::ofstream outfile(tmp.c_str());
  std::string tree =
      "           \033[0;34m*\033[0m             \033[0;33m,\n\
                       _/^\\_\n\
                      <     >\n\
     \033[0;34m*\033[0;33m                 /.-.\\         \033[0;34m*\033[0m\n\
              \033[0;34m*\033[0m        `/&\\`                   \033[0;34m*\033[0m\n\
                      ,@.*;@,\n\
                     /_o.I %_\\    \033[0;34m*\033[0m\n\
        \033[0;34m*\033[0m           (`'--:o(_@;\n\
                   /`;--.,__ `')             \033[0;34m*\033[0m\n\
                  ;@`o % O,*`'`&\\\n\
            \033[0;34m*\033[0m    (`'--)_@ ;o %'()\\      \033[0;34m*\033[0m\n\
                 /`;--._`''--._O'@;\n\
                /&*,()~o`;-.,_ `\"\"`)\n\
     \033[0;34m*\033[0m          /`,@ ;+& () o*`;-';\\\n\
               (`\"\"--.,_0 +% @' &()\\\n\
               /-.,_    ``''--....-'`)  \033[0;34m*\033[0m\n\
          \033[0;34m*\033[0m    /@%;o`:;'--,.__   __.'\\\n\
              ;*,&(); @ % &^;~`\"`o;@();         \033[0;34m*\033[0m\n\
              /(); o^~; & ().o@*&`;&%O\\\n\
              `\"=\"==\"\"==,,,.,=\"==\"===\"`\n\
           \033[0;34m__.----.\033[0m(\\\033[34m-\033[0m''#####\033[34m---...___...-----._\n\
         '`\033[0m         \\)_`\"\"\"\"\"`\n\
                 .--' ')\n\
               o(  )_-\\\n\
                 `\"\"\"` `";
  if (!outfile.is_open())
    throw std::ios_base::failure("🚨 파일을 열 수 없습니다 🚨");
  outfile << tree << std::endl;
  outfile.close();
}