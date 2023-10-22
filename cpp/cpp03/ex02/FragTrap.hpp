#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap(std::string name);
  FragTrap(const FragTrap& scav);
  virtual ~FragTrap();
  FragTrap& operator=(const FragTrap& scav);
  void highFivesGuys();
  virtual void attack(const std::string& target);
};

#endif