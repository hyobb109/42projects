/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:39:45 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 18:36:06 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name) : name_(name) {};

Zombie::~Zombie() {
    std::cout << name_ << " got destroyed\n";    
}

void Zombie::announce() {
    std::cout << name_ << ": " << MESSAGE << '\n';
}

void Zombie::setName(std::string name) {
    name_ = name;
}