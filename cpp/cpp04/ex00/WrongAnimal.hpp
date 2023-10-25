#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
 protected:
  std::string type;

 public:
  WrongAnimal();
  WrongAnimal(std::string type);
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal& wrong_animal);
  WrongAnimal& operator=(const WrongAnimal& wrong_animal);
  std::string getType() const;
  void makeSound() const;
};

#endif