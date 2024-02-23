#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
 private:
  RPN(const RPN& copy);
  RPN& operator=(const RPN& copy);
  bool isOperator(int c);
  void pushResult(std::stack<double>& s, int op);

 public:
  RPN();
  ~RPN();
  void calculate(std::string input);
};

#endif