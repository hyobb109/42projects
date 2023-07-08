/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:26 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/08 22:46:30 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
	std::string cmd;
	PhoneBook phoneBook;
	while (1)
	{
		std::cin >> cmd;
		if (std::cin.eof()) {
			std::cout << "EOF error" << '\n';
			return 1;
		}
		// 개행까지 남아있는 버퍼를 지운다 "ADD 'ADD'"
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (!cmd.compare("EXIT"))
			return 0;
		else if (!cmd.compare("ADD")) {
			
		} else if (!cmd.compare("SEARCH")) {
			
		}
		std::cout << cmd << '\n';
	}
	return 0;
}