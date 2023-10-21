#include "ClapTrap.hpp"

int main() {
  ClapTrap pikachu("피카츄");
  pikachu.setAttackDamage(3);
  pikachu.getStatus();
  ClapTrap ditto("메타몽");
  ditto.setAttackDamage(10);
  ditto.getStatus();
  pikachu.attack("메타몽");
  pikachu.getStatus();
  ditto.takeDamage(pikachu.getAttackDamage());
  ditto.getStatus();
  ditto.attack("피카츄");
  ditto.getStatus();
  pikachu.takeDamage(ditto.getAttackDamage());
  pikachu.getStatus();
  pikachu.attack("메타몽");
  pikachu.beRepaired(20);
  ditto.getStatus();
  ditto.beRepaired(20);
  ditto.getStatus();
  return 0;
}