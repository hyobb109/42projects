#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* materias[4];

 public:
  MateriaSource();
  virtual ~MateriaSource();
  MateriaSource(const MateriaSource& ms);
  MateriaSource& operator=(const MateriaSource& ms);
  virtual void learnMateria(AMateria* m);
  virtual AMateria* createMateria(std::string const& type);
};

#endif