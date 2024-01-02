#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container<T>> {
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

  std::Container::iterator begin() { return c.begin(); }

  std::Container::iterator end() { return c.end(); }
};
#endif