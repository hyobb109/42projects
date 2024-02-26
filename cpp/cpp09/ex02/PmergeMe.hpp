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
#define GREEN "\033[0;32m"

class PmergeMe {
 private:
  std::vector<int> v_;
  std::deque<int> d_;
  double v_time_;
  double d_time_;
  // vector
  void sortVector_(size_t pair_cnt, size_t pair_size);
  void makeVPairs_(size_t pair_cnt, size_t pair_size, size_t span);

  // deque
  void sortDeque_();
  void makeDPairs_(size_t pair_cnt, size_t pair_size, size_t span);

  // for debugging
  void printVector_();
  void printDeque_();

  PmergeMe(const PmergeMe& copy);
  PmergeMe& operator=(const PmergeMe& copy);
  PmergeMe();

 public:
  PmergeMe(char** av);
  ~PmergeMe();
  void sortVector();
  void sortDeque();
  const std::vector<int>& getVector() const;
  const std::deque<int>& getDeque() const;
  const double& getVTime() const;
  const double& getDTime() const;
};

#endif