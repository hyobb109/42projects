#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 4

// void check() { system("leaks a.out"); }

int main() {
  // atexit(check);
  std::cout << "======Animals======\n";
  Animal *animals[SIZE];
  for (int i = 0; i < SIZE; i++) {
    i % 2 ? animals[i] = new Dog() : animals[i] = new Cat();
    std::cout << "type: " << animals[i]->getType() << "\n";
    animals[i]->makeSound();
    animals[i]->speak();
    std::cout << "===================\n";
  }

  std::cout << "======Copy Cat======\n";
  *animals[0] = *animals[2];
  animals[0]->makeSound();
  animals[0]->speak();
  animals[0]->think("집에 언제 가냥");
  animals[0]->speak();
  animals[2]->speak();
  std::cout << "======Copy Dog======\n";
  *animals[1] = *animals[3];
  animals[1]->makeSound();
  animals[1]->speak();
  animals[1]->think("집에 언제 가지 멍멍");
  animals[1]->speak();
  animals[3]->speak();
  std::cout << "====deleting...====\n";
  for (int i = 0; i < SIZE; i++) {
    delete animals[i];
    std::cout << "===================\n";
  }
  return 0;
}
