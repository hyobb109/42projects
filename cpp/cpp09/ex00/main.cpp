#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Usage: ./btc <filename>" << std::endl;
    return 1;
  }
  // Your program must take a file as argument.
  std::string filename = av[1];
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }
  // | 기준 스플릿 -> 날짜, value Map에 저장하면 될 듯

  // Each line in this file must use the following format: "date | value".

  // A valid date will always be in the following format: Year-Month-Day.
  // 2009-01-02 이전 날짜는 모두 에러
  // A valid value must be either a float or a positive integer, between 0 and
  // 1000.
}