/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/09 21:14:56 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::saveInfo(int flag) {
	std::string info;
	while (1) {
		std::getline(std::cin, info);
		if (std::cin.eof()) {
			std::cout << "EOF Error\n";
			exit(1);
		}
		if (info.length())
			break;
		else {
			std::cout << "The information cannot be empty!\n";
		}
	}
	if (flag == FIRST_NAME)
		firstName = info;
	else if (flag == LAST_NAME)
		lastName = info;
	else if (flag == NICKNAME)
		nickname = info;
	else if (flag == PHONE_NUMBER)
		phoneNumber = info;
	else if (flag == SECRET)
		secret = info;
}

std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickname() {
	return nickname;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

std::string Contact::getSecret() {
	return secret;
}

void Contact::displayNames() {
	char tmp[11];
	tmp[9] = '.';
	tmp[10] = '\0';
	if (firstName.length() > 10) {
		firstName.copy(tmp, 9, 0);
		std::cout << std::setw(10) << tmp << "|";
	} else {
		std::cout << std::setw(10) << firstName << "|";
	}
	if (lastName.length() > 10) {
		lastName.copy(tmp, 9, 0);
		std::cout << std::setw(10) << tmp << "|";
	} else {
		std::cout << std::setw(10) << lastName << "|";
	}
	if (nickname.length() > 10) {
		nickname.copy(tmp, 9, 0);
		std::cout << std::setw(10) << tmp << "\n";
	} else {
		std::cout << std::setw(10) << nickname << "\n";
	}
}