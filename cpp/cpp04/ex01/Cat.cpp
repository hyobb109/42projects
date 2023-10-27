#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain("나는 고양이로소이다")) {
  std::cout << "고양이가 나타났다!\n";
}

Cat::~Cat() {
  delete brain;
  std::cout << "고양이가 도망갔다!\n";
}

Cat::Cat(const Cat& cat) : Animal(cat.type), brain(new Brain()) {
  *brain = *cat.brain;
  std::cout << "고양이가 또 나타났다!\n";
}

Cat& Cat::operator=(const Cat& cat) {
  if (this != &cat) {
    type = cat.type;
    *brain = *cat.brain;
  }
  return *this;
}

Cat& Cat::operator=(const Animal& cat) {
  if (this != &cat) {
    *this = dynamic_cast<const Cat&>(cat);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "야옹~😺\n"; }

void Cat::speak() const {
  const std::string* ideas = brain->getIdeas();
  std::cout << ideas[0] << "\n";
}

void Cat::think(std::string idea) const { brain->setIdeas(idea); }