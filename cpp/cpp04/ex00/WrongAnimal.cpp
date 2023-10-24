#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "이상한 동물이 나타났다!\n"; }

WrongAnimal::~WrongAnimal() { std::cout << "이상한 동물이 도망갔다!\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal& wrong_animal)
    : type(wrong_animal.type) {
  std::cout << "이상한 동물이 또 나타났다!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrong_animal) {
  if (this != &wrong_animal) {
    type = wrong_animal.type;
  }
  return *this;
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const { std::cout << "...❓\n"; }