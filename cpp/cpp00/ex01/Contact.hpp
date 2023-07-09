/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/09 21:14:00 by hyobicho         ###   ########.fr       */
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
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	
	public:
	void 		saveInfo(int flag);
	void 		displayNames();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getSecret();
};

#endif