#include "DiamondTrap.hpp"

int main() {
  DiamondTrap celebi("세레비");
  FragTrap chikorita("치코리타");
  ScavTrap pikachu("피카츄");
  ClapTrap ditto("메타몽");
  celebi.whoAmI();
  celebi.attack("치코리타");
  chikorita.takeDamage(celebi.getAttackDamage());
  ditto.setAttackDamage(10);
  ditto.attack("세레비");
  celebi.takeDamage(ditto.getAttackDamage());
  celebi.beRepaired(20);
  return 0;
}