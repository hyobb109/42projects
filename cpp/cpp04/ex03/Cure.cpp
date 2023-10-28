#include "Cure.hpp"

Cure::Cure() : AMateria("cure") { std::cout << "Cure 생성!\n"; }

Cure::~Cure() { std::cout << "Cure 소멸!\n"; }

Cure::Cure(const Cure& cure) : AMateria(cure.type) {
  std::cout << "Cure 복사!\n";
}

Cure& Cure::operator=(const Cure& cure) {
  if (this != &cure) type = cure.type;
  return *this;
}

Cure* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *\n";
}