#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  AMateria* slot[4];
  bool equipped[4];

 public:
  Character(std::string name);
  virtual ~Character();
  Character(const Character& c);
  Character& operator=(const Character& c);
  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};

#endif