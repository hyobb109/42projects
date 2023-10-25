#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "========Animal========\n";
  const Animal* meta = new Animal();
  std::cout << "type: " << meta->getType() << '\n';
  meta->makeSound();
  delete meta;
  std::cout << "========Dog========\n";
  const Animal* dog = new Dog();
  std::cout << "type: " << dog->getType() << '\n';
  dog->makeSound();
  delete dog;
  std::cout << "========Cat========\n";
  const Animal* cat = new Cat();
  std::cout << "type: " << cat->getType() << '\n';
  cat->makeSound();
  delete cat;
  std::cout << "========Wrong Cat========\n";
  const WrongAnimal* wrong_cat = new WrongCat();
  std::cout << "type: " << wrong_cat->getType() << '\n';
  wrong_cat->makeSound();
  delete wrong_cat;
  return 0;
}