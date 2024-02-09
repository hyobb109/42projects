#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
 private:
  std::vector<int> _v;
  std::deque<int> _d;
  void printElement(int el);

 public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& copy);
  PmergeMe& operator=(const PmergeMe& copy);

  void printVector();
  void printDeque();
};

#endif