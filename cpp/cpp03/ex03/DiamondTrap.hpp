#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string name_;

 public:
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap& diamond);
  virtual ~DiamondTrap();
  DiamondTrap& operator=(const DiamondTrap& diamond);
  void whoAmI();
};

#endif