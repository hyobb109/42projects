#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain("나는 고양이로소이다")) {
  std::cout << "고양이가 나타났다!\n";
}

Cat::~Cat() {
  delete brain;
  std::cout << "고양이가 도망갔다!\n";
}

Cat::Cat(const Cat& cat) : Animal(cat.type) {
  std::cout << "고양이가 또 나타났다!\n";
}

Cat& Cat::operator=(const Cat& cat) {
  if (this != &cat) type = cat.type;
  return *this;
}

void Cat::makeSound() const { std::cout << "야옹~😺\n"; }

void Cat::speak() const {
  const std::string* ideas = brain->getIdeas();
  for (int i = 0; i < 10; i++) std::cout << ideas[i] << "\n";
}