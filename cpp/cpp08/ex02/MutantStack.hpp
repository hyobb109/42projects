#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
 public:
  MutantStack() : std::stack() {}

  ~MutantStack() {}

  MutantStack(const MutantStack& m) : std::stack(m) {}

  MutantStack& operator=(const MutantStack& m) {
    if (this != &m) {
      // copy
    }
    return *this;
  }
};
#endif