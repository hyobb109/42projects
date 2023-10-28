#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(std::string name) : ICharacter(), name(name) {
  std::cout << "Character " << name << " 생성!\n";
}

// the Materias must be deleted when a Character is destroyed.
Character::~Character() { std::cout << "Character " << name << " 소멸!\n"; }

// During copy, the Materias of a Character must be deleted before the new ones
// are added to their inventory.
Character::Character(const Character& c) : ICharacter(), name(c.name) {
  std::cout << "Character " << name << " 복사!\n";
}

Character& Character::operator=(const Character& c) {
  if (this != &c) name = c.name;
  return *this;
}

std::string const& Character::getName() const { return name; }

//  equip the Materias in the first empty slot they find.
// In case they try to add a Materia to a full inventory, or use/unequip an
// unexisting Materia, don’t do anything
void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (!slot[i]) {
      slot[i] = m->clone();
    }
  }
}

// must NOT delete the Materia
void Character::unequip(int idx) {}

// use the Materia at the slot[idx], and pass the target parameter to the
// AMateria::use function.
void Character::use(int idx, ICharacter& target) {}