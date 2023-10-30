#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(std::string name) : ICharacter(), name(name) {
  std::cout << "Character " << name << " 생성!\n";
  for (int i = 0; i < 4; i++) equipped[i] = false;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (slot[i])
      delete slot[i];
    else
      return;
  }
  std::cout << "Character " << name << " 소멸!\n";
}

Character::Character(const Character& c) : ICharacter(), name(c.name) {
  std::cout << "Character " << name << " 복사!\n";
  for (int i = 0; i < 4; i++) {
    if (slot[i]) delete slot[i];
    slot[i] = c.slot[i]->clone();
    equipped[i] = c.equipped[i];
  }
}

Character& Character::operator=(const Character& c) {
  if (this != &c) {
    name = c.name;
    for (int i = 0; i < 4; i++) {
      if (slot[i]) delete slot[i];
      slot[i] = c.slot[i]->clone();
      equipped[i] = c.equipped[i];
    }
  }
  return *this;
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m) {
  if (slot[3]) return;
  for (int i = 0; i < 4; i++) {
    if (!slot[i]) {
      slot[i] = m->clone();
      equipped[i] = true;
    }
  }
}

void Character::unequip(int idx) {
  if (slot[idx] && equipped[idx]) {
    equipped[idx] = false;
    std::cout << "SLOT " << idx << "장착 해제!\n";
  }
}

void Character::use(int idx, ICharacter& target) {
  if (slot[idx] && equipped[idx]) slot[idx]->use(target);
}