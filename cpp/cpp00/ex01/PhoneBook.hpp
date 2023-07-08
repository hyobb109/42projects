/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:29 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/08 21:25:58 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
	// 접근 지시자 -> 외부에서 멤버 접근 가능 여부 지시
	private: // 객체 외부에서 접근할 수 없음, 명시하지 않으면 private이 기본
	Contact	contacts[8];
	
	public:
	void add(Contact newContact, int idx) {
		contacts[idx] = newContact;
	}
	// display a specific contact
	void search(int idx) {
		// index, first name, last name, nickname
		std::cout << "Index: " << idx;
		// 각 칸은 10자, 오른쪽 정렬, 길면 마지막 글자 .으로 대체
		// index 를 입력하라고 띄우고 한 줄에 하나씩 출력 
	}
};

#endif