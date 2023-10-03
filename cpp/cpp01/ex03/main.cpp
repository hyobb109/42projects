#include <stdlib.h>

#include "HumanA.hpp"
#include "HumanB.hpp"

// void leak() { system("leaks violence"); }

int main() {
  //   atexit(leak);
  std::cout << "======Human A======" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  std::cout << "======Human B======" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}