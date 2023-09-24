#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  const std::string& weaponType = weapon.getType();
  std::cout << name << " attacks with their " << weaponType << std::endl;
}