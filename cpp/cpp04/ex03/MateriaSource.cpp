#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
  // std::cout << "MateriaSource 생성!\n";
  for (int i = 0; i < 4; i++) {
    materias[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  // std::cout << "MateriaSource 소멸!\n";
  for (int i = 0; i < 4; i++) {
    if (materias[i])
      delete materias[i];
    else
      return;
  }
}

MateriaSource::MateriaSource(const MateriaSource& ms) : IMateriaSource() {
  // std::cout << "MateriaSource 복사!\n";
  for (int i = 0; i < 4; i++) {
    if (materias[i]) delete materias[i];
    materias[i] = ms.materias[i]->clone();
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
  if (this != &ms) {
    for (int i = 0; i < 4; i++) {
      if (materias[i]) delete materias[i];
      materias[i] = ms.materias[i]->clone();
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m) {
    std::cout << "⛔️ERROR⛔️ Invalid Materia!\n";
    return;
  }
  if (materias[3]) {
    std::cout << "MateriaSource can know at most 4 Materias\n";
    delete m;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (!materias[i]) {
      materias[i] = m;
      std::cout << "📚 learning " << m->getType() << "... (" << i + 1
                << "/4)\n";
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (materias[i] && type == materias[i]->getType())
      return materias[i]->clone();
  }
  return 0;
}