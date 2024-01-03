#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "MutantStack.hpp"

enum CMDS { EMPTY, SIZE, TOP, PUSH, POP, PRINT };

template <typename Container>
void printStack(Container& mstack) {
  typename Container::iterator it;
  for (it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::map<std::string, int> cmds;
  cmds["empty"] = EMPTY;
  cmds["size"] = SIZE;
  cmds["top"] = TOP;
  cmds["push"] = PUSH;
  cmds["pop"] = POP;
  cmds["print"] = PRINT;
  MutantStack<int> mstack;
  std::cout << "=====MutantStack=====\n";
  while (1) {
    std::string command;
    std::cout << "명령어: empty, size, top, push, pop, print, exit\n";
    std::cin >> command;
    if (command == "exit") break;
    if (cmds.find(command) == cmds.end()) continue;
    int cmd = cmds[command];

    switch (cmd) {
      case EMPTY:
        mstack.empty() ? std::cout << "true" << std::endl
                       : std::cout << "false" << std::endl;

        break;
      case SIZE:
        std::cout << "size: " << mstack.size() << std::endl;
        break;
      case TOP:
        mstack.empty() ? std::cout << "스택이 비었습니다!" << std::endl
                       : std::cout << "top: " << mstack.top() << std::endl;
        break;
      case PUSH: {
        std::cout << "숫자를 입력하세요" << std::endl;
        std::string input_num;
        std::cin >> input_num;
        int num = atoi(input_num.c_str());
        mstack.push(num);
        break;
      }
      case POP:
        if (mstack.empty())
          std::cout << "스택이 비었습니다!" << std::endl;
        else
          mstack.pop();
        break;
      default:
        printStack(mstack);
        break;
    }
  }
  std::cout << "=====Stack=====\n";
  std::stack<int> s(mstack);
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;
  return 0;
}