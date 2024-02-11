#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"

class PmergeMe {
 private:
 public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe& copy);
  PmergeMe& operator=(const PmergeMe& copy);
  void sort(std::vector<int>& v);
  void sort(std::deque<int>& d);
  void print(const std::vector<int>& v);
  void print(const std::deque<int>& d);
};

#endif