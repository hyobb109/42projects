#include "ScavTrap.hpp"

int main() {
  ScavTrap pikachu("피카츄");
  ClapTrap ditto("메타몽");
  ditto.setAttackDamage(10);
  ditto.attack("피카츄");
  pikachu.takeDamage(ditto.getAttackDamage());
  pikachu.attack("메타몽");
  ditto.takeDamage(pikachu.getAttackDamage());
  pikachu.beRepaired(10);
  pikachu.guardGate();
  return 0;
}