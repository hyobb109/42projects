/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:40:03 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 18:36:11 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    Zombie(std::string name);
    ~Zombie();
    void    announce();
    void    setName(std::string name);
};

#endif