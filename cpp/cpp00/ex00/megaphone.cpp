/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:51:27 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 15:18:06 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		std::string str = "";
		for (int i = 1; av[i]; i++)
			str += av[i];
		for (size_t i = 0; i < str.size(); i++)
			str[i] = std::toupper(str[i]);
		std::cout << str << std::endl;
	}
	return 0;
}