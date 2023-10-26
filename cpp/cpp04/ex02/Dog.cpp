#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain("나는 강아지로소이다")) {
  std::cout << "강아지가 나타났다!\n";
}

Dog::~Dog() {
  delete brain;
  std::cout << "강아지가 도망갔다!\n";
}

Dog::Dog(const Dog& dog) : Animal(dog.type) {
  std::cout << "강아지가 또 나타났다!\n";
}

Dog& Dog::operator=(const Dog& dog) {
  if (this != &dog) {
    type = dog.type;
    *brain = *dog.brain;
  }
  return *this;
}

Dog& Dog::operator=(const Animal& dog) {
  if (this != &dog) {
    *this = dynamic_cast<const Dog&>(dog);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "멍멍!🐶\n"; }

void Dog::speak() const {
  const std::string* ideas = brain->getIdeas();
  std::cout << ideas[0] << "\n";
}

void Dog::think(std::string idea) const { brain->setIdeas(idea); }