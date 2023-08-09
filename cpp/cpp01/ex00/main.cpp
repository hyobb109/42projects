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

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    // It creates a zombie, name it, and return it 
    // so you can use it outside of the function scope.
    std::cout << "===newZombie===\n";
    Zombie *z = newZombie("apple");
    z->announce();
    delete z;
    
    // It creates a zombie, name it, and the zombie announces itself
    std::cout << "===randomChump===\n";
    randomChump("banana");
    return 0;
}
