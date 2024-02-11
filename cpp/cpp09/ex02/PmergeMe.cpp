#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
  (void)copy;
  return *this;
}

void PmergeMe::sort(std::vector<int>& v) {
  std::cout << v.size() << " vector\n";
}

void PmergeMe::sort(std::deque<int>& d) { std::cout << d.size() << " deque\n"; }

// for debugging
void PmergeMe::print(const std::vector<int>& v) {
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::print(const std::deque<int>& d) {
  for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}