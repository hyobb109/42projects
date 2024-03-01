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
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"

class PmergeMe {
 private:
  std::vector<size_t> jacobsthal_;
  std::vector<int> v_;
  std::deque<int> d_;
  double v_time_;
  double d_time_;
  // vector
  void sortVector_(size_t pair_cnt, size_t pair_size);
  void makeVPairs_(size_t pair_cnt, size_t pair_size, size_t span);
  void insertNumber_(size_t pair_cnt, size_t span);
  void binary_search_insert_(std::vector<int>& main_chain,
                             std::vector<int>& pending, size_t target_idx,
                             size_t e, size_t span);

  // deque
  void sortDeque_();
  void makeDPairs_(size_t pair_cnt, size_t pair_size, size_t span);

  // for debugging
  void print_(const std::vector<int>& v, const std::string& tag) const;
  void print_(const std::deque<int>& d, const std::string& tag) const;

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
  void printVector(const std::string& tag) const;
  void printDeque(const std::string& tag) const;
};

#endif