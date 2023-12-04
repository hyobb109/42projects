#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <vector>

class Span {
 private:
  std::vector<int> v;
  unsigned int n_;
  Span();

 public:
  Span(unsigned int n);
  ~Span();
  Span(const Span& s);
  Span& operator=(const Span& s);
  void addNumber(int num);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  void fillSpan(unsigned int n);
  std::size_t getVectorSize() const;
};

#endif