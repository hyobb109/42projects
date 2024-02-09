
#include "PmergeMe.hpp"

static void checkArg(std::string av) {
  if (av.find_first_not_of("0123456789") != std::string::npos)
    throw std::runtime_error("Error");
}

int main(int ac, char** av) {
  // 인자 에러 처리
  try {
    std::vector<int> v;
    std::deque<int> d;
    if (ac < 2) throw std::runtime_error("Error");
    for (int i = 1; i < ac; i++) {
      checkArg(av[i]);
      int num = atoi(av[i]);
      if (num <= 0) throw std::runtime_error("Error");
      v.push_back(num);
      d.push_back(num);
    }
    PmergeMe p;
    std::cout << "Before: ";
    p.print(v);
    p.sort(v);
    p.sort(d);
    std::cout << "After: ";
    p.print(v);

    // get time to process
    std::cout << "Time to process a range of " << v.size()
              << "elements with std::vector: "
              << "[time]" << std::endl;
    std::cout << "Time to process a range of " << d.size()
              << "elements with std::deque: "
              << "[time]" << std::endl;
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}