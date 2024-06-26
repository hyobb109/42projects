#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  Cat();
  virtual ~Cat();
  Cat(const Cat& cat);
  virtual Cat& operator=(const Animal& cat);
  Cat& operator=(const Cat& cat);
  virtual void makeSound() const;
  virtual void speak() const;
  void think(std::string idea) const;
};
#endif