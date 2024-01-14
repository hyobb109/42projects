#include <cstdio>

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Usage: ./btc <filename>" << std::endl;
    return 1;
  }
  std::ifstream infile(av[1]);
  if (!infile.is_open()) {
    std::cerr << "🚨 입력 파일을 열 수 없습니다 🚨" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange btc;
    btc.saveDatabase("data.csv");
    btc.exchange(infile);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  infile.close();
  return (0);
}
