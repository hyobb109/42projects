#include "Animal.hpp"

Animal::Animal() : type("Animal") { std::cout << "동물이 나타났다!\n"; }

Animal::Animal(std::string type) : type(type) {
  std::cout << "동물이 나타났다!\n";
}

Animal::~Animal() { std::cout << "동물이 도망갔다!\n"; }

Animal::Animal(const Animal& animal) : type(animal.type) {
  std::cout << "동물이 또 나타났다!\n";
}

Animal& Animal::operator=(const Animal& animal) {
  if (this != &animal) type = animal.type;
  return *this;
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "...❓\n"; }
