#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define MESSAGE "BraiiiiiiinnnzzzZ..."

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string newName);
    ~Zombie();
    void    announce();
    void    setName(std::string newName);
};

#endif