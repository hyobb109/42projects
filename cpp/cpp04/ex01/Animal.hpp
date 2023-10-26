#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 protected:
  std::string type;

 public:
  Animal();
  Animal(std::string type);
  virtual ~Animal();
  Animal(const Animal& animal);
  virtual Animal& operator=(const Animal& animal);
  std::string getType() const;
  virtual void makeSound() const;
  virtual void speak() const = 0;
  virtual void think(std::string idea) const = 0;
};

#endif