#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum FormName {
  SHRUBBERRY,
  ROBOTOMY,
  PRESIDENTIAL,
};

class Intern {
 public:
  Intern();
  ~Intern();
  Intern(const Intern& intern);
  Intern& operator=(const Intern& intern);
  AForm* makeForm(std::string name, std::string target);
};

#endif