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
  int max = *std::max_element(v.begin(), v.end());
  int min = *std::min_element(v.begin(), v.end());
  return max - min;
}

void Span::fillSpan(unsigned int n) {
  //   std::vector<int>::iterator iter = v.end() - 1;
  (void)n;
}