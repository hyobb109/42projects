#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(std::string name) : ICharacter(), name(name) {
  // std::cout << "Character " << name << " 생성!\n";
  for (int i = 0; i < 4; i++) {
    slot[i] = NULL;
    equipped[i] = false;
  }
}

Character::~Character() {
  // std::cout << "Character " << name << " 소멸!\n";
  for (int i = 0; i < 4; i++) {
    if (slot[i])
      delete slot[i];
    else
      return;
  }
}

Character::Character(const Character& c) : ICharacter(), name(c.name) {
  // std::cout << "Character " << name << " 복사!\n";
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
  if (!m) {
    std::cout << "⛔️ERROR⛔️ Unknown Materia type!\n";
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (!equipped[i]) {
      if (slot[i]) delete slot[i];
      slot[i] = m;
      equipped[i] = true;
      std::cout << "🧙 " << name << " has equipped the Materia " << m->getType()
                << " in SLOT " << i << "\n";
      return;
    }
  }
  std::cout << "The inventroy is full\n";
  delete m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) return;
  if (slot[idx] && equipped[idx]) {
    equipped[idx] = false;
    std::cout << "🧙 " << name << " has unequipped the Materia "
              << slot[idx]->getType() << " in SLOT " << idx << "\n";
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3) {
    std::cout << "⛔️ERROR⛔️ Invalid index!\n";

    return;
  }
  if (slot[idx]) {
    if (equipped[idx])
      slot[idx]->use(target);
    else
      std::cout << "⛔️ERROR⛔️ The Materia is not equipped!\n";
  }
}
