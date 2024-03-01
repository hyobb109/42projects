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
  size_t cnt = v_.size() / 2;
  jacobsthal_.push_back(1);
  jacobsthal_.push_back(3);
  for (size_t i = 2; jacobsthal_.back() < cnt; i++) {
    int num = jacobsthal_[i - 1] + jacobsthal_[i - 2] * 2;
    jacobsthal_.push_back(num);
  }
}

// sort vector
void PmergeMe::makeVPairs_(size_t pair_cnt, size_t pair_size, size_t span) {
  // std::cout << "pair_cnt: " << pair_cnt << ", pair_size: " << pair_size <<
  // "\n";
  std::vector<int>::iterator it = v_.begin();
  for (size_t i = 0; i < pair_cnt; i++) {
    // std::cout << "a: " << *it << ", b: " << *(it + span) << "\n";
    if (*it < *(it + span)) {
      std::swap_ranges(it, it + span, it + span);
    }
    it += pair_size;
  }
  // printVector("원본");
}

void PmergeMe::binary_search_insert_(std::vector<int>& main_chain,
                                     std::vector<int>& pending,
                                     size_t target_idx, size_t span) {
  size_t s = 0;
  // size_t e = main_chain.size() - span;
  size_t e = main_chain.size() / span - 1;
  size_t mid;
  size_t cnt = 0;
  while (s < e) {
    mid = s + (e - s) / 2;
    std::cout << "s: " << main_chain[s * span]
              << " mid: " << main_chain[mid * span]
              << " e: " << main_chain[e * span] << "\n";
    if (pending[target_idx] < main_chain[mid * span])
      e = mid;
    else
      s = mid + 1;
    ++cnt;
  }
  std::cout << BLUE << "비교 횟수: " << cnt << " pending[" << target_idx
            << "]: " << pending[target_idx] << " main[" << s * span
            << "]: " << main_chain[s * span] << RESET << std::endl;
  main_chain.insert(main_chain.begin() + s * span, pending.begin() + target_idx,
                    pending.begin() + target_idx + span);
  print_(main_chain, "main");
}

void PmergeMe::insertNumber_(size_t pair_cnt, size_t span) {
  std::vector<int> main_chain;
  std::vector<int> pending;
  std::vector<int>::iterator v_it = v_.begin();
  for (size_t i = 0; i < pair_cnt; i++) {
    main_chain.insert(main_chain.end(), v_it, v_it + span);
    v_it += span;
    pending.insert(pending.end(), v_it, v_it + span);
    v_it += span;
    if (i == pair_cnt - 1 &&
        static_cast<size_t>(std::distance(v_it, v_.end())) >= span) {
      pending.insert(pending.end(), v_it, v_it + span);
    }
  }
  print_(main_chain, "main");
  print_(pending, "pend");
  std::cout << "============\n";
  // 첫 번째 원소는 맨 앞에 삽입
  main_chain.insert(main_chain.begin(), pending.begin(),
                    pending.begin() + span);
  print_(main_chain, "main");
  bool end_flag = false;
  for (size_t i = 1; !end_flag; i++) {
    size_t prev = (jacobsthal_[i - 1] - 1) * span;
    size_t target_idx = (jacobsthal_[i] - 1) * span;
    std::cout << "jacobsthal[" << i << "]: " << jacobsthal_[i]
              << " target_idx: " << target_idx << " prev: " << prev
              << std::endl;
    if (target_idx == pending.size() - 1)
      end_flag = true;
    else if (target_idx >= pending.size()) {
      target_idx = pending.size() - span;
      end_flag = true;
    }
    // target_idx부터 그 전까지
    while (target_idx > prev) {
      binary_search_insert_(main_chain, pending, target_idx, span);
      target_idx -= span;
    }
  }
  copy(main_chain.begin(), main_chain.end(), v_.begin());
  print_(v_, "원본");
}

void PmergeMe::sortVector_(size_t pair_cnt, size_t pair_size) {
  // make pairs
  makeVPairs_(pair_cnt, pair_size, pair_size / 2);
  if (pair_cnt > 1) sortVector_(pair_cnt / 2, pair_size * 2);
  // recursive
  std::cout << YELLOW << "pair_cnt: " << pair_cnt
            << ", pair_size: " << pair_size << " span: " << pair_size / 2
            << RESET << "\n";
  // insert
  insertNumber_(pair_cnt, pair_size / 2);
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

void PmergeMe::printVector(const std::string& tag) const {
  std::cout << tag << ": " << GREEN;
  for (std::vector<int>::const_iterator it = v_.begin(); it != v_.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << RESET << "(is_sorted: " << MAGENTA << std::boolalpha
            << std::is_sorted(v_.begin(), v_.end()) << RESET << ")"
            << std::endl;
}

void PmergeMe::printDeque(const std::string& tag) const {
  std::cout << tag << ": " << GREEN;
  for (std::deque<int>::const_iterator it = d_.begin(); it != d_.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << RESET << std::endl;
}

// for debugging
void PmergeMe::print_(const std::vector<int>& v, const std::string& tag) const {
  std::cout << tag << ": " << GREEN;
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << RESET << std::endl;
}

void PmergeMe::print_(const std::deque<int>& d, const std::string& tag) const {
  std::cout << tag << ": " << GREEN;
  for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << RESET << std::endl;
}
