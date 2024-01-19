#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) { (void)copy; }

RPN& RPN::operator=(const RPN& copy) {
  (void)copy;
  return *this;
}

bool RPN::isOperator(int c) {
  return (c == '-' || c == '+' || c == '*' || c == '/');
}

void RPN::pushResult(std::stack<double>& s, int op) {
  double nums[2];
  for (int j = 1; j >= 0; j--) {
    nums[j] = s.top();
    s.pop();
  }
  // std::cout << "equation: " << nums[0] << " " << (char)op << " " << nums[1]
  //           << std::endl;
  switch (op) {
    case '-':
      s.push(nums[0] - nums[1]);
      break;
    case '+':
      s.push(nums[0] + nums[1]);
      break;
    case '*':
      s.push(nums[0] * nums[1]);
      break;
    case '/':
      s.push(nums[0] / nums[1]);
      break;
  }
  // std::cout << "res: " << s.top() << std::endl;
}

void RPN::calculate(std::string input) {
  std::stack<double> s;
  size_t len = input.length();
  for (size_t i = 0; i < len; i++) {
    char c = input[i];
    if (c == ' ') continue;
    if (isdigit(c)) {
      s.push(c - '0');
    } else if (isOperator(c) && s.size() > 1) {
      pushResult(s, c);

    } else {
      std::cout << "Error" << std::endl;
      return;
    }
  }
  s.size() == 1 ? std::cout << s.top() << std::endl
                : std::cout << "Error" << std::endl;
}