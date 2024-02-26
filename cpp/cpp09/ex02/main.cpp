#include "PmergeMe.hpp"

int main(int ac, char** av) {
  try {
    if (ac < 2) throw std::runtime_error("Error");
    PmergeMe p(av);
    std::cout << "Before: ";
    p.printVector();
    // sort
    p.sortVector();
    p.sortDeque();
    // result
    std::cout << "After: ";
    p.printVector();
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