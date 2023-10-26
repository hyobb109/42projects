#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain* brain;

 public:
  Dog();
  virtual ~Dog();
  Dog(const Dog& dog);
  virtual Dog& operator=(const Animal& dog);
  Dog& operator=(const Dog& dog);
  virtual void makeSound() const;
  virtual void speak() const;
  void think(std::string idea) const;
};

#endif