#include "Dog.hpp"

Dog::Dog() : Animal() {
  type = "Dog";
  std::cout << "강아지가 나타났다!\n";
}
Dog::~Dog() { std::cout << "강아지가 도망갔다!\n"; }
Dog::Dog(const Dog& dog) : Animal() {
  type = dog.type;
  std::cout << "강아지가 또 나타났다!\n";
}
Dog& Dog::operator=(const Dog& dog) {
  if (this != &dog) type = dog.type;
  return *this;
}
void Dog::makeSound() const { std::cout << "멍멍!🐶\n"; }