#include <ctime>
#include <iostream>

#include "Span.hpp"
#define BASIC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"

void printSpanData(Span& sp) {
  std::cout << "shortest: " << sp.shortestSpan() << std::endl;
  std::cout << "longest: " << sp.longestSpan() << std::endl;
  std::cout << "size: " << sp.getVectorSize() << std::endl;
  std::cout << "=========================" << std::endl;
}

int main() {
  std::srand(std::time(NULL));
  try {
    std::cout << GREEN << "Span(5)" << BASIC << std::endl;
    Span span1 = Span(5);
    span1.addNumber(6);
    printSpanData(span1);
    span1.addNumber(3);
    printSpanData(span1);
    span1.addNumber(17);
    printSpanData(span1);
    span1.addNumber(9);
    printSpanData(span1);
    span1.addNumber(-8);
    printSpanData(span1);
    span1.addNumber(-8);
    printSpanData(span1);

  } catch (std::exception& e) {
    std::cerr << RED << e.what() << BASIC << std::endl;
  }

  try {
    std::cout << GREEN << "Span(10000)" << BASIC << std::endl;
    Span span2 = Span(10000);
    for (int i = 0; i < 100000; ++i) {
      span2.fillSpan(2000);
      printSpanData(span2);
    }
  } catch (std::exception& e) {
    std::cerr << RED << e.what() << BASIC << std::endl;
  }
  return 0;
}