#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap {
 public:
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap& scav);
  ~ScavTrap();
};

#endif