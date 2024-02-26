#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
  (void)copy;
  return *this;
}

PmergeMe::PmergeMe(char** av) : v_time_(0), d_time_(0) {
  for (int i = 1; av[i]; i++) {
    std::string str = av[i];
    if (str.find_first_not_of("0123456789") != std::string::npos)
      throw std::runtime_error("Error");
    int num = atoi(av[i]);
    if (num <= 0) throw std::runtime_error("Error");
    v_.push_back(num);
    d_.push_back(num);
  }
}

void PmergeMe::makePairs_(size_t pair_cnt, size_t pair_size, size_t span) {
  std::cout << "pair_cnt: " << pair_cnt << "\n";
  std::vector<int>::iterator it = v_.begin();
  for (size_t i = 0; i < pair_cnt; i++) {
    std::cout << "a: " << *it << " b: " << *(it + span) << "\n";
    if (*it < *(it + span)) {
      std::swap_ranges(it, it + span, it + span);
      printVector();
    }
    it += pair_size;
  }
}

// sort vector
void PmergeMe::sortVector_(size_t pair_cnt, size_t pair_size) {
  // make pairs
  makePairs_(pair_cnt, pair_size, pair_size / 2);
  if (pair_cnt == 1) return;
  // recursive
  sortVector_(pair_cnt / 2, pair_size * 2);
  // insert
}

// sort deque
void PmergeMe::sortDeque_() {}

void PmergeMe::sortVector() {
  clock_t start = clock();
  if (v_.size() == 2) {
    if (v_[0] > v_[1]) std::swap(v_[0], v_[1]);
  } else if (v_.size() > 2)
    sortVector_(v_.size() / 2, 2);
  clock_t end = clock();
  v_time_ = static_cast<double>(end - start);
}

void PmergeMe::sortDeque() {
  clock_t start = clock();
  sortDeque_();
  clock_t end = clock();
  d_time_ = static_cast<double>(end - start);
}

const std::vector<int>& PmergeMe::getVector() const { return v_; }

const std::deque<int>& PmergeMe::getDeque() const { return d_; }

const double& PmergeMe::getVTime() const { return v_time_; }

const double& PmergeMe::getDTime() const { return d_time_; }

// for debugging
void PmergeMe::printVector() {
  for (std::vector<int>::const_iterator it = v_.begin(); it != v_.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printDeque() {
  for (std::deque<int>::const_iterator it = d_.begin(); it != d_.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}