#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 protected:
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;
  const static unsigned int MAX = 4294967295;
  void getStatus();

 public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& clap);
  ~ClapTrap();
  ClapTrap& operator=(const ClapTrap& clap);
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void setAttackDamage(unsigned int amount);
  unsigned int getAttackDamage();
};

#endif