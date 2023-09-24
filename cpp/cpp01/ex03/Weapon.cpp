#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){};

Weapon::~Weapon() {}

// member function that returns a const reference to type.
const std::string& Weapon::getType() const { return type; }

// member function that sets type using the new one passed as parameter.
void Weapon::setType(std::string newType) { type = newType; }