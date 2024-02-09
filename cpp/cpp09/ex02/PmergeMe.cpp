#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {}

void PmergeMe::printElement(int el) { std::cout << el << " "; }

void PmergeMe::printVector() {
  for_each(_v.begin(), _v.end(), printElement);
  std::cout << std::endl;
}

void PmergeMe::printDeque() {
  for_each(_d.begin(), _d.end(), printElement);
  std::cout << std::endl;
}
