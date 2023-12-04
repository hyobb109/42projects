#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : n_(n) {}

Span::~Span() {}

Span::Span(const Span& s) : v(s.v), n_(s.n_) {}

Span& Span::operator=(const Span& s) {
  if (this != &s) {
    v = s.v;
    n_ = s.n_;
  }
  return *this;
}

void Span::addNumber(int num) {
  if (v.size() == n_) throw std::range_error("Out of Range!");
  v.push_back(num);
}

unsigned int Span::shortestSpan() const {
  if (v.empty() || v.size() == 1) return 0;
  unsigned int span;
  unsigned int min = UINT_MAX;
  std::vector<int> copy = v;
  sort(copy.begin(), copy.end());
  for (std::vector<int>::iterator iter = copy.begin(); iter != copy.end() - 1;
       ++iter) {
    span = *(iter + 1) - *iter;
    if (span < min) min = span;
  }
  return min;
}

unsigned int Span::longestSpan() const {
  if (v.empty() || v.size() == 1) return 0;
  int max = *std::max_element(v.begin(), v.end());
  int min = *std::min_element(v.begin(), v.end());
  return max - min;
}

void Span::fillSpan(unsigned int n) {
  for (unsigned int i = 0; i < n; ++i) {
    addNumber(std::rand());
  }
}

std::size_t Span::getVectorSize() const { return v.size(); }
