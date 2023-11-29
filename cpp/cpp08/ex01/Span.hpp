#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span {
 private:
  unsigned int n_;
  Span();

 public:
  Span(unsigned int n);
  Span(const Span& s);
  Span& operator=(const Span& s);
  void addNumber(unsigned int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  void fillSpan();
};

#endif