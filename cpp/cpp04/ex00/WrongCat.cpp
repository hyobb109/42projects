#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  type = "Wrong Cat";
  std::cout << "이상한 고양이가 나타났다!\n";
}

WrongCat::~WrongCat() { std::cout << "이상한 고양이가 도망갔다!\n"; }

WrongCat::WrongCat(const WrongCat& wrong_cat) : WrongAnimal() {
  type = wrong_cat.type;
  std::cout << "이상한 고양이가 또 나타났다!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& wrong_cat) {
  if (this != &wrong_cat) type = wrong_cat.type;
  return *this;
}

void WrongCat::makeSound() const { std::cout << "야옹~😺\n"; }