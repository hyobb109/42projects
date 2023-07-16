/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:26 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/09 22:04:22 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	std::string cmd;
	PhoneBook phoneBook;
	int cnt = 0;
	while (1)
	{
		std::cout << "Enter a command: ADD / SEARCH / EXIT\n";
		std::cin >> cmd;
		if (std::cin.eof()) {
			std::cout << "EOF Error\n";
			return 1;
		}
		// 개행까지 남아있는 버퍼를 지운다
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (cmd == "EXIT")
			return 0;
		// Save a new contact
		else if (cmd == "ADD") {
			Contact newContact;
			std::cout << "First Name: ";
			newContact.saveInfo(FIRST_NAME);
			std::cout << "Last Name: ";
			newContact.saveInfo(LAST_NAME);
			std::cout << "Nickname: ";
			newContact.saveInfo(NICKNAME);
			std::cout << "Phone Number: ";
			newContact.saveInfo(PHONE_NUMBER);
			std::cout << "Darkest Secret: ";
			newContact.saveInfo(SECRET);
			phoneBook.add(newContact, cnt++ % 8);
			std::cout <<"======SAVED!======\n";
		} else if (cmd == "SEARCH") {
			// Display saved contacts
			phoneBook.displayAll();
			// prompt the user again for the index of the entry to display
			std::string num;
			std::cout << "Enter the index to display\n";
			std::cin >> num;
			if (std::cin.eof()) {
				std::cout << "EOF Error\n";
				return 1;
			}
			if (num.length() > 1 || !isdigit(num[0]) || num[0] > '7') {
				std::cout << "Invalid index!\n";
			} else {
				phoneBook.search(num[0] - '0');
			}
		}
	}
	return 0;
}