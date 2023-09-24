#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
  // It creates a zombie, name it, and return it
  // so you can use it outside of the function scope.
  std::cout << "===newZombie===" << std::endl;
  Zombie* z = newZombie("apple");
  z->announce();
  delete z;

  // It creates a zombie, name it, and the zombie announces itself
  std::cout << "===randomChump===" << std::endl;
  randomChump("banana");
  return 0;
}
