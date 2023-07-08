/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/08 22:30:04 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

void Contact::saveContact() {
	std::string s;
	for (int i = 0; i < 5; i++) {
		std::cin >> s;
		if (std::cin.eof()) {
			std::cout << "EOF error" << '\n';
		}
		
		// if (s)
	}
}

void Contact::getFirstName() {
	std::cout << firstName << '\n';
}

void Contact::getLastName() {
	std::cout << lastName << '\n';
}

void Contact::getNickname() {
	std::cout << nickname << '\n';
}

void Contact::getPhoneNumber() {
	std::cout << phoneNumber << '\n';
}