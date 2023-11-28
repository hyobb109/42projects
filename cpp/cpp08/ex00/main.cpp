

#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(int ac, char** av) {
  if (ac != 3) {
    std::cout << "Usage: ./a.out <integer1> <integer2>" << std::endl;
    return 1;
  }

  int target1 = std::atoi(av[1]);
  int target2 = std::atoi(av[2]);
  std::vector<int> v;
  std::deque<int> d;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    d.push_back(i);
  }

  try {
    std::cout << "=====vector=====" << std::endl;
    std::cout << easyfind(v, target1) << std::endl;
    std::cout << "=====deque=====" << std::endl;
    std::cout << easyfind(d, target2) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}