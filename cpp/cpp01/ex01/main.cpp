#include "Zombie.hpp"
#include <stdlib.h>

Zombie* zombieHorde(int N, std::string name);

int main(int ac, char** av) {
    if (ac == 3) {
        int n = atoi(av[1]);
        Zombie* zombies = zombieHorde(n, av[2]);
        if (!zombies) {
            std::cout << "Error! : N should be more than 0" << std::endl;
            return 1;
        }
        for (int i = 0; i < n; i++) {
            zombies[i].announce();
        }
        std::cout << "============" << std::endl;
        delete[]zombies;
    }
    else {
        std::cout << "Usage: ./zombieHorde [N] [name]" << std::endl;
    }
    return 0;
}
