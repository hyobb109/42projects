#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits>
#include <string>

const unsigned int MAX = std::numeric_limits<unsigned int>::max();

class ClapTrap {
 private:
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

 public:
  ClapTrap(std::string name);
  ~ClapTrap();
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void setAttackDamage(unsigned int amount);
  unsigned int getAttackDamage();
  void getStatus();
};

#endif