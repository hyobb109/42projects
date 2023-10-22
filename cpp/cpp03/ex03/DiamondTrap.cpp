#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name), FragTrap(name), ScavTrap(name), name_(name) {
  hit_points_ = FragTrap::hit_points_;        // 100
  energy_points_ = ScavTrap::energy_points_;  // 50
  attack_damage_ = 30;                        // 30
  ClapTrap::name_ = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond)
    : ClapTrap(diamond.name_),
      FragTrap(diamond.name_),
      ScavTrap(diamond.name_) {
  std::cout << "앗! 야생의 DiamondTrap " << name_ << "(이)가 또 나타났다!\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name_ << "(이)가 도망쳤다!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamond) {
  name_ = diamond.name_;
  hit_points_ = diamond.hit_points_;
  energy_points_ = diamond.energy_points_;
  attack_damage_ = diamond.attack_damage_;
  return *this;
}

// display both its name and its ClapTrap name
void DiamondTrap::whoAmI() {
  std::cout << "안녕! 나는 DiamondTrap " << name_ << "(" << ClapTrap::name_
            << ")(이)야!\n";
}
