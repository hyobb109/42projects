#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  FragTrap chikorita("치코리타");
  ScavTrap pikachu("피카츄");
  ClapTrap ditto("메타몽");
  chikorita.highFivesGuys();
  ditto.setAttackDamage(10);
  ditto.attack("피카츄");
  pikachu.takeDamage(ditto.getAttackDamage());
  ditto.attack("치코리타");
  chikorita.takeDamage(ditto.getAttackDamage());
  pikachu.attack("메타몽");
  ditto.takeDamage(pikachu.getAttackDamage());
  chikorita.attack("메타몽");
  ditto.takeDamage(pikachu.getAttackDamage());
  ditto.attack("피카츄");
  pikachu.takeDamage(ditto.getAttackDamage());
  chikorita.beRepaired(20);
  pikachu.guardGate();
  return 0;
}