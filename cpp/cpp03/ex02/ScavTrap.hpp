#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& scav);
  virtual ~ScavTrap();
  ScavTrap& operator=(const ScavTrap& scav);
  void guardGate();
  virtual void attack(const std::string& target);
};

#endif