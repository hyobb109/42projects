/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:21:33 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 18:39:01 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

Zombie* zombieHorde(int N, std::string name );

int main(int ac, char **av) {
    if (ac == 3) {
        int n = atoi(av[1]);
        Zombie *zombies = zombieHorde(n, av[2]);
        if (!zombies) {
            std::cout << "Error!\n";
            return 1;
        }
        for (int i = 0; i < n; i++) {
            zombies[i].announce();
        }
        delete []zombies;
        std::cout << "============\n";
    }
    return 0;
}
