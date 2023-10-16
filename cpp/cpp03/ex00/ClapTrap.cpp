#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
  std::cout << "앗! 야생의 ClapTrap " << name_ << "(이)가 나타났다!\n";
}

ClapTrap::ClapTrap(const ClapTrap& clap)
    : name_(clap.name_),
      hit_points_(clap.hit_points_),
      energy_points_(clap.energy_points_),
      attack_damage_(clap.attack_damage_) {
  std::cout << "앗! 야생의 ClapTrap " << name_ << "(이)가 또 나타났다!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clap) {
  name_ = clap.name_;
  hit_points_ = clap.hit_points_;
  energy_points_ = clap.energy_points_;
  attack_damage_ = clap.attack_damage_;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << "(이)가 도망쳤다!\n";
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points_ == 0) {
    std::cout << "ClapTrap " << name_ << "(은)는 기절한 상태다!\n";
  } else if (energy_points_ == 0) {
    std::cout << "ClapTrap " << name_ << "(은)는 에너지가 없다!\n";
  } else {
    energy_points_--;
    std::cout << "ClapTrap " << name_ << "(이)가" << target << "에게 "
              << attack_damage_ << "의 데미지를 입혔다!\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points_ == 0) {
    std::cout << "ClapTrap " << name_ << "(은)는 이미 기절했다!\n";
  } else {
    std::cout << "ClapTrap " << name_ << "(이)가 " << amount
              << "의 데미지를 입었다!\n";
    if (hit_points_ < amount) amount = hit_points_;
    hit_points_ -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hit_points_ == 0) {
    std::cout << "ClapTrap " << name_ << "(은)는 기절한 상태다!\n";
  } else if (energy_points_ == 0) {
    std::cout << "ClapTrap " << name_ << "(은)는 에너지가 없다!\n";
  } else {
    energy_points_--;
    if (hit_points_ + amount < hit_points_) amount = MAX - hit_points_;
    hit_points_ += amount;
    std::cout << "ClapTrap " << name_ << "(이)가 " << amount
              << "(총 HP: " << hit_points_ << ")만큼 체력을 회복했다!\n";
  }
}

void ClapTrap::setAttackDamage(unsigned int amount) { attack_damage_ = amount; }

unsigned int ClapTrap::getAttackDamage() { return attack_damage_; }

void ClapTrap::getStatus() {
  std::cout << "=========================\n";
  std::cout << "이름: " << name_ << "\n";
  std::cout << "HP: " << hit_points_ << "\n";
  std::cout << "에너지: " << energy_points_ << "\n";
  std::cout << "공격력: " << attack_damage_ << "\n";
  std::cout << "========================\n";
}