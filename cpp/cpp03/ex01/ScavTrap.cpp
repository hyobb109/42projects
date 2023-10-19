#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "앗! 야생의 ScavTrap " << name << "(이)가 나타났다!\n";
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav.name_) {
  std::cout << "앗! 야생의 ScavTrap " << name_ << "(이)가 또 나타났다!\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name_ << "(이)가 도망쳤다!\n";
}