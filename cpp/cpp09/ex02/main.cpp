#include "PmergeMe.hpp"

int main(int ac, char** av) {
  try {
    if (ac < 2) throw std::runtime_error("Error");
    PmergeMe p(av);
    // sort
    p.sortVector();
    // p.printDeque("Before");
    p.sortDeque();
    // result
    p.printVector("After");
    // p.printDeque("After");

    std::cout << "Time to process a range of " << p.getVector().size()
              << " elements with std::vector: " << p.getVTime()
              << " clock ticks" << std::endl;
    std::cout << "Time to process a range of " << p.getDeque().size()
              << " elements with std::deque: " << p.getDTime() << " clock ticks"
              << std::endl;
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}