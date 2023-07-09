/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:29 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/09 21:55:41 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class PhoneBook {
	// 접근 지시자 -> 외부에서 멤버 접근 가능 여부 지시
	private: // 객체 외부에서 접근할 수 없음, 명시하지 않으면 private이 기본
	Contact	contacts[8];
	
	public:
	void	add(Contact newContact, int idx);
	int		search(int idx);
	void	displayAll();
};

#endif