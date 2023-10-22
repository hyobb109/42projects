#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "앗! 야생의 FragTrap " << name << "(이)가 나타났다!\n";
  hit_points_ = 100;
  energy_points_ = 100;
  attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& frag) : ClapTrap(frag.name_) {
  std::cout << "앗! 야생의 FragTrap " << name_ << "(이)가 또 나타났다!\n";
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name_ << "(이)가 도망쳤다!\n";
}

FragTrap& FragTrap::operator=(const FragTrap& frag) {
  name_ = frag.name_;
  hit_points_ = frag.hit_points_;
  energy_points_ = frag.energy_points_;
  attack_damage_ = frag.attack_damage_;
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name_ << "(이)가 하이파이브를 했다!\n";
}
