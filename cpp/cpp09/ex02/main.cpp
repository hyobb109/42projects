#include "PmergeMe.hpp"

template <typename T>
static void print(const T& c) {
  for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int ac, char** av) {
  try {
    if (ac < 2) throw std::runtime_error("Error");
    PmergeMe p(av);
    std::cout << "Before: ";
    print(p.getVector());
    // sort
    p.sortVector();
    p.sortDeque();
    // result
    std::cout << "After: ";
    print(p.getVector());
    std::cout << "Time to process a range of " << p.getVector().size()
              << " elements with std::vector: " << p.getVTime() << " ms"
              << std::endl;
    std::cout << "Time to process a range of " << p.getDeque().size()
              << " elements with std::deque: " << p.getDTime() << " ms"
              << std::endl;
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}