#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& newWeapon) { weapon = &newWeapon; }

void HumanB::attack() {
  if (!weapon) {
    std::cout << name << " has no weapon" << std::endl;
  } else {
    const std::string& weaponType = weapon->getType();
    std::cout << name << " attacks with their " << weaponType << std::endl;
  }
}