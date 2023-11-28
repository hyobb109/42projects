

#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Usage: ./a.out <integer>" << std::endl;
    return 1;
  }

  int target = std::atoi(av[1]);
  std::vector<int> v;
  std::deque<int> d;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    d.push_back(i);
  }

  try {
    std::cout << "=====vector=====" << std::endl;
    std::cout << easyfind(v, target) << std::endl;
    std::cout << "=====deque=====" << std::endl;
    std::cout << easyfind(d, target) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}