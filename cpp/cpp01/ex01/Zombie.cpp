#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string newName) : name(newName){};

Zombie::~Zombie() { std::cout << name << " got destroyed" << std::endl; }

void Zombie::announce() { std::cout << name << ": " << MESSAGE << std::endl; }

void Zombie::setName(std::string newName) { name = newName; }