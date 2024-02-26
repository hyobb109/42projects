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

// sort vector
void PmergeMe::makeVPairs_(size_t pair_cnt, size_t pair_size, size_t span) {
  std::cout << "pair_cnt: " << pair_cnt << ", pair_size: " << pair_size << "\n";
  std::vector<int>::iterator it = v_.begin();
  for (size_t i = 0; i < pair_cnt; i++) {
    std::cout << "a: " << *it << ", b: " << *(it + span) << "\n";
    if (*it < *(it + span)) {
      std::swap_ranges(it, it + span, it + span);
    }
    it += pair_size;
  }
  printVector();
}

void PmergeMe::insertNumber_(size_t pair_size) {
  std::vector<int> main_chain(pair_size);  // reserve로 공간할당만 해주기
  std::copy(v_.begin(), v_.begin() + pair_size, main_chain.begin());
  print_(main_chain);
}

void PmergeMe::sortVector_(size_t pair_cnt, size_t pair_size) {
  // make pairs
  makeVPairs_(pair_cnt, pair_size, pair_size / 2);
  if (pair_cnt == 1) return;
  // recursive
  sortVector_(pair_cnt / 2, pair_size * 2);
  std::cout << YELLOW << "pair_cnt: " << pair_cnt
            << ", pair_size: " << pair_size << RESET << "\n";

  // insert
  insertNumber_(pair_size);
}

void PmergeMe::sortVector() {
  clock_t start = clock();
  if (v_.size() > 1) sortVector_(v_.size() / 2, 2);
  clock_t end = clock();
  v_time_ = static_cast<double>(end - start);
}

// sort deque
void PmergeMe::sortDeque_() {}

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

void PmergeMe::printVector() {
  for (std::vector<int>::const_iterator it = v_.begin(); it != v_.end(); it++) {
    std::cout << GREEN << *it << " ";
  }
  std::cout << RESET << std::endl;
}

void PmergeMe::printDeque() {
  for (std::deque<int>::const_iterator it = d_.begin(); it != d_.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// for debugging
void PmergeMe::print_(const std::vector<int>& v) {
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    std::cout << GREEN << *it << " ";
  }
  std::cout << RESET << std::endl;
}

void PmergeMe::print_(const std::deque<int>& d) {
  for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}