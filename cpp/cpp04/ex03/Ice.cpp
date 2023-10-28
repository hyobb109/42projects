#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { std::cout << "Ice 생성!\n"; }

Ice::~Ice() { std::cout << "Ice 소멸!\n"; }

Ice::Ice(const Ice& ice) : AMateria(ice.type) { std::cout << "Ice 복사!\n"; }

Ice& Ice::operator=(const Ice& ice) {
  if (this != &ice) type = ice.type;
  return *this;
}

Ice* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}