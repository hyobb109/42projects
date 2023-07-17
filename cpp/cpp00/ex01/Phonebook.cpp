/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:37:05 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 14:45:14 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add(Contact newContact, int idx) {
    contacts[idx] = newContact;
}

// display a specific contact
void PhoneBook::search(int idx) {
    if (contacts[idx].getData(FIRST_NAME) == "") {
        std::cout << "Nothing to display\n";
        return ;
    }
	std::cout << "===☎ CONTACT ☎===\n";
    std::cout << "First Name: " << contacts[idx].getData(FIRST_NAME) << "\n";
    std::cout << "Last Name: " << contacts[idx].getData(LAST_NAME) << "\n";
    std::cout << "Nickname: " << contacts[idx].getData(NICKNAME) << "\n";
    std::cout << "Phone Number: " << contacts[idx].getData(PHONE_NUMBER) << "\n";
    std::cout << "Darkest Secret: " << contacts[idx].getData(SECRET) << "\n";
	std::cout << "==================\n";
}

bool PhoneBook::displayAll() {
    if (contacts[0].getData(FIRST_NAME) == "") {
        std::cout << "Nothing saved. Please add a new contact.\n";
        return false;
    }
    std::cout << std::setw(35) << "☎ PHONE BOOK ☎\n";
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < 8; i++) {
        if (contacts[i].getData(FIRST_NAME) == "")
            break;
        std::cout << std::setw(10) << i << "|";           
        contacts[i].displayName(FIRST_NAME, '|');
        contacts[i].displayName(LAST_NAME, '|');
        contacts[i].displayName(NICKNAME, '\n');
    }
    return true;
}