/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:37:05 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/09 22:09:30 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add(Contact newContact, int idx) {
    contacts[idx] = newContact;
}

// display a specific contact
int PhoneBook::search(int idx) {
    if (idx < 0 || idx > 7) {
        std::cout << "The index is out of range!\n";
        return -1;
    }
    if (contacts[idx].getFirstName() == "") {
        std::cout << "Nothing to display\n";
        return idx;
    }
    std::cout << "First Name: " << contacts[idx].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[idx].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[idx].getNickname() << "\n";
    std::cout << "Phone Number: " << contacts[idx].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[idx].getSecret() << "\n";
    return idx;
}

void PhoneBook::displayAll() {
    std::cout << std::setw(35) << "☎ PHONE BOOK ☎\n";
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < 8; i++) {
        if (contacts[i].getFirstName() == "")
            break;
        std::cout << std::setw(10) << i << "|";
        contacts[i].displayNames();
    }
}