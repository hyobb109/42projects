#include "ClapTrap.hpp"

int main() {
  ClapTrap pikachu("피카츄");
  pikachu.setAttackDamage(3);
  pikachu.getStatus();
  ClapTrap onix("메타몽");
  onix.setAttackDamage(2);
  onix.getStatus();
  pikachu.attack("메타몽");
  pikachu.getStatus();
  onix.takeDamage(pikachu.getAttackDamage());
  onix.getStatus();
  onix.attack("피카츄");
  onix.getStatus();
  pikachu.takeDamage(onix.getAttackDamage());
  pikachu.getStatus();
  onix.takeDamage(pikachu.getAttackDamage());
  onix.getStatus();
  onix.beRepaired(MAX);
  onix.getStatus();
  return 0;
}