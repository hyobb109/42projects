#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span {
 private:
  unsigned int n_;

 public:
  Span();
  Span(unsigned int n);
  Span(const Span& s);
  Span& operator=(const Span& s);
  void addNumber(unsigned int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  class FullException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif