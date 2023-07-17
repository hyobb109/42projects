/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 14:15:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>
#include <iostream>
#include <iomanip>

enum Info {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET
};

class Contact {
	private:
	std::string data[5];
	
	public:
	void 		saveData(std::string prompt, int flag);
	void 		displayName(int flag, char c);
	std::string getData(int flag);
};

#endif