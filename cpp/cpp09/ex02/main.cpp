#include <cstdlib>

#include "PmergeMe.hpp"
#define RESET "\033[0m"
#define RED "\033[31m"

int main(int ac, char** av) {
  // 인자 에러 처리
  try {
    std::vector<int> v;
    std::deque<int> d;
    if (ac < 2) throw std::runtime_error("Error");
    for (int i = 1; i < ac; i++) {
      int num = atoi(av[i]);
      if (num < 0) throw std::runtime_error("Error");
      v.push_back(num);
      d.push_back(num);
    }

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}