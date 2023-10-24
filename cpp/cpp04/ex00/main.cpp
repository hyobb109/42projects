#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* cat = new Cat();
  const Animal* dog = new Dog();
  const WrongAnimal* wrong_cat = new WrongCat();
  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << wrong_cat->getType() << " " << std::endl;
  cat->makeSound();
  dog->makeSound();
  wrong_cat->makeSound();
  meta->makeSound();
  delete meta;
  delete dog;
  delete cat;
  delete wrong_cat;
  return 0;
}