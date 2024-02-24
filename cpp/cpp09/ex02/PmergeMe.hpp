#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"

class PmergeMe {
 private:
  std::vector<int> v_;
  std::deque<int> d_;
  double v_time_;
  double d_time_;
  void sortVector_(size_t pair_size);
  void sortDeque_();

  PmergeMe(const PmergeMe& copy);
  PmergeMe& operator=(const PmergeMe& copy);
  PmergeMe();

 public:
  PmergeMe(char** av);
  ~PmergeMe();
  // void makePairs(size_t pair_size);
  void sortVector();
  void sortDeque();
  const std::vector<int>& getVector() const;
  const std::deque<int>& getDeque() const;
  const double& getVTime() const;
  const double& getDTime() const;
  // for debugging
  void printVector();
  void printDeque();
};

#endif