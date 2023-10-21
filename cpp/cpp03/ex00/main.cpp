#include "ClapTrap.hpp"

int main() {
  ClapTrap pikachu("피카츄");
  pikachu.setAttackDamage(3);
  ClapTrap ditto("메타몽");
  ditto.setAttackDamage(10);
  pikachu.attack("메타몽");
  ditto.takeDamage(pikachu.getAttackDamage());
  ditto.attack("피카츄");
  pikachu.takeDamage(ditto.getAttackDamage());
  pikachu.attack("메타몽");
  pikachu.beRepaired(20);
  ditto.beRepaired(20);
  return 0;
}