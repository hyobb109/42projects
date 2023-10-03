#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
  std::cout
      << "[ DEBUG ]\n"
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout
      << "[ INFO ]\n"
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn't be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "[ WARNING ]\n"
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error() {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  static std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (size_t i = 0; i < level.length(); i++) level[i] = std::toupper(level[i]);

  int lv = -1;
  while (++lv < 4) {
    if (level == levels[lv]) {
      break;
    }
  }
  switch (lv) {
    case DEBUG:
      debug();
    case INFO:
      info();
    case WARNING:
      warning();
    case ERROR:
      error();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
  }
}