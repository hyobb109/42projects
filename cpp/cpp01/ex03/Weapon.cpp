#include "Weapon.hpp"

const std::string& getType() {
    std::string& typeRef = type;
    return typeRef;
}

void setType(std::string newType) {
    type = newType;
}