#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& ms) : IMateriaSource() {}

MateriaSource& MateriaSource::operator=(const MateriaSource* ms) {}

void MateriaSource::learnMateria(AMateria*) {}

AMateria* MateriaSource::createMateria(std::string const& type) {}