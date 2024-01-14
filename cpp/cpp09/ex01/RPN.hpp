#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <string>

class RPN {
 public:
  RPN();
  ~RPN();
  RPN(const RPN& copy);
  RPN& operator=(const RPN& copy);
  void calculate(std::string input);
};

#endif