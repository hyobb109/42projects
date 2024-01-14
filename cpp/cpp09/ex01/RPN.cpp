#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) {}

RPN& RPN::operator=(const RPN& copy) { return *this; }

void RPN::calculate(std::string input) {
  std::stack<int> s;
  // 파싱 오류 -> return;
  // 0 ~ 9 까지의 숫자, - + / * , 공백만 받음
  //./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
  // number => push, operator => stack 모든 원소 연산해서 스택 바꿔줌
}