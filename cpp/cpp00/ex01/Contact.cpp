/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:58:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/07/17 14:44:00 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::saveData(std::string prompt, int flag) {
  std::string info;
  while (1) {
    std::cout << prompt;
    std::getline(std::cin, info);
    if (std::cin.eof()) {
      std::cout << "EOF Error\n";
      exit(1);
    }
    // 앞, 뒤 공백 삭제
    std::size_t s = info.find_first_not_of(" \t\n\r\f\v");
    std::size_t e = info.find_last_not_of(" \t\n\r\f\v");
    // std::cout << "s: " << s << " e: " << e << '\n';
    // 공백만 들어온 경우
    if (e >= info.length()) {
      std::cout << "The information cannot be empty!\n";
      continue;
    } else {
      // info가 바뀌므로 뒤에부터 삭제해줌
      info.erase(e + 1);
      //   std::cout << " trimmed:" << info << "$\n";
      info.erase(0, s);
      //   std::cout << " trimmed:" << info << "$\n";
    }
    if (info.length())
      break;
    else {
      std::cout << "The information cannot be empty!\n";
    }
  }
  data[flag] = info;
}

std::string Contact::getData(int flag) { return data[flag]; }

void Contact::displayName(int flag, char c) {
  char tmp[11];
  tmp[9] = '.';
  tmp[10] = '\0';
  if (data[flag].length() > 10) {
    data[flag].copy(tmp, 9, 0);
    std::cout << std::setw(10) << tmp << c;
  } else {
    std::cout << std::setw(10) << data[flag] << c;
  }
}