#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "앗! 야생의 ScavTrap " << name << "(이)가 나타났다!\n";
  hit_points_ = 100;
  energy_points_ = 50;
  attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav.name_) {
  std::cout << "앗! 야생의 ScavTrap " << name_ << "(이)가 또 나타났다!\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name_ << "(이)가 도망쳤다!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scav) {
  if (this != &scav) {
    name_ = scav.name_;
    hit_points_ = scav.hit_points_;
    energy_points_ = scav.energy_points_;
    attack_damage_ = scav.attack_damage_;
  }
  return *this;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name_ << "(이)가 문지기가 되었다!\n";
}

void ScavTrap::attack(const std::string& target) {
  if (hit_points_ == 0) {
    std::cout << "ScavTrap " << name_ << "(은)는 기절한 상태다!\n";
  } else if (energy_points_ == 0) {
    std::cout << "ScavTrap " << name_ << "(은)는 에너지가 없다!\n";
  } else {
    energy_points_--;
    std::cout << "ScavTrap " << name_ << "(이)가 " << target << "에게 "
              << attack_damage_ << "의 데미지를 입혔다!\n";
  }
  getStatus();
}