/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:26 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 14:44:01 by hyobicho         ###   ########.fr       */
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (cmd == "EXIT")
			return 0;
		// Save a new contact
		else if (cmd == "ADD") {
			Contact newContact;
			newContact.saveData("First Name: ", FIRST_NAME);
			newContact.saveData("Last Name: ", LAST_NAME);
			newContact.saveData("Nickname: ", NICKNAME);
			newContact.saveData("Phone Number: ", PHONE_NUMBER);
			newContact.saveData("Darkest Secret: ", SECRET);
			phoneBook.add(newContact, cnt++ % 8);
			std::cout <<"======SAVED!======\n";
		} else if (cmd == "SEARCH") {
			// Display saved contacts
			if (phoneBook.displayAll())
			{
				// prompt the user again for the index of the entry to display
				std::string num;
				std::cout << "Enter the index to display\n";
				std::getline(std::cin, num);
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
	}
	return 0;
}