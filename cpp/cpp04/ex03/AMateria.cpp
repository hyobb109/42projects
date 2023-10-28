#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type(type) {
  std::cout << "Materia " << type << " 생성!\n";
}

AMateria::~AMateria() { std::cout << "Materia " << type << " 소멸!\n"; }

AMateria::AMateria(const AMateria& m) : type(m.type) {
  std::cout << "Materia " << type << " 복사!\n";
}

AMateria& AMateria::operator=(const AMateria& m) {
  if (this != &m) type = m.type;
  return *this;
}

std::string const& AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) { std::cout << "???\n"; }