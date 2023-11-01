#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// void check() { system("leaks a.out"); }

int main() {
  // atexit(check);
  std::cout << "=======================\n";
  IMateriaSource* src = new MateriaSource();
  std::cout << "🧪 마법 배우는 중...\n";
  src->learnMateria(NULL);
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Cure());
  std::cout << "=======================\n";

  ICharacter* hippo = new Character("하마");

  std::cout << "✨ 하마 마법 장착 중...\n";
  AMateria* tmp;
  tmp = src->createMateria("blabla");
  hippo->equip(tmp);
  tmp = src->createMateria("ice");
  hippo->equip(tmp);
  tmp = src->createMateria("cure");
  hippo->equip(tmp);
  tmp = src->createMateria("ice");
  hippo->equip(tmp);
  tmp = src->createMateria("cure");
  hippo->equip(tmp);
  tmp = src->createMateria("cure");
  hippo->equip(tmp);
  std::cout << "=======================\n";
  ICharacter* alpaca = new Character("알파카");

  std::cout << "🔮 하마->알파카 마법 사용 중...\n";
  hippo->use(0, *alpaca);
  hippo->use(1, *alpaca);
  hippo->use(2, *alpaca);
  hippo->use(3, *alpaca);
  hippo->use(4, *alpaca);
  std::cout << "=======================\n";
  hippo->unequip(3);
  hippo->use(3, *alpaca);
  hippo->equip(src->createMateria("ice"));
  hippo->use(3, *alpaca);
  std::cout << "=======================\n";

  delete alpaca;
  delete hippo;
  delete src;

  return 0;
}