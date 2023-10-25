#include "Cat.hpp"
#include "Dog.hpp"

// void check() { system("leaks a.out"); }

int main() {
  // atexit(check);
  std::cout << "========Dog========\n";
  const Animal* dog = new Dog();
  std::cout << "========Cat========\n";
  const Animal* cat = new Cat();
  // create and fill an array of Animal objects (half Dog, half Cat)
  std::cout << "======Animals======\n";
  const Animal* animals[2];
  animals[0] = dog;
  animals[1] = cat;
  for (int i = 0; i < 2; i++) {
    std::cout << animals[i]->getType() << "\n";
    animals[i]->makeSound();
    animals[i]->speak();
    delete (animals[i]);
    std::cout << "===================\n";
  }
  return 0;
}