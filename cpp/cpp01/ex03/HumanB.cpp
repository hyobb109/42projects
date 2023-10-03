#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& newWeapon) { weapon = &newWeapon; }

void HumanB::attack() {
  if (!weapon) {
    std::cout << name << " has no weapon" << std::endl;
  } else {
    std::cout << name << " attacks with their " << weapon->getType()
              << std::endl;
  }
}