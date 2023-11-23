#include <iostream>

#include "whatever.hpp"

int main() {
  int a = 1, b = 2;
  std::cout << "=====int=====" << std::endl;
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "min(" << a << ", " << b << ") ? : " << min(a, b) << std::endl;
  std::cout << "max(" << a << ", " << b << ") ? : " << max(a, b) << std::endl;
  std::cout << "swapping..." << std::endl;
  swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;
  std::cout << "min(" << a << ", " << b << ") ? : " << min(a, b) << std::endl;
  std::cout << "max(" << a << ", " << b << ") ? : " << max(a, b) << std::endl;

  std::cout << "\n=====string=====" << std::endl;
  std::string s1 = "black", s2 = "pink";
  std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;
  std::cout << "min(" << s1 << ", " << s2 << ") ? : " << min(s1, s2)
            << std::endl;
  std::cout << "max(" << s1 << ", " << s2 << ") ? : " << max(s1, s2)
            << std::endl;
  std::cout << "swapping..." << std::endl;
  swap(s1, s2);
  std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;
  std::cout << "min(" << s1 << ", " << s2 << ") ? : " << min(s1, s2)
            << std::endl;
  std::cout << "max(" << s1 << ", " << s2 << ") ? : " << max(s1, s2)
            << std::endl;

  return 0;
}