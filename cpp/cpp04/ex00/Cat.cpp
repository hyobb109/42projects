#include "Cat.hpp"

Cat::Cat() : Animal() {
  type = "Cat";
  std::cout << "고양이가 나타났다!\n";
}

Cat::~Cat() { std::cout << "고양이가 도망갔다!\n"; }

Cat::Cat(const Cat& cat) : Animal() {
  type = cat.type;
  std::cout << "고양이가 또 나타났다!\n";
}

Cat& Cat::operator=(const Cat& cat) {
  if (this != &cat) type = cat.type;
  return *this;
}

void Cat::makeSound() const { std::cout << "야옹~😺\n"; }
