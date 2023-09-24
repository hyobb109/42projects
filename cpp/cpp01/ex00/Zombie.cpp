#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {};

Zombie::~Zombie() {
    std::cout << name << " got destroyed" << std::endl;;    
}

void Zombie::announce() {
    std::cout << name << ": " << MESSAGE << std::endl;
}
