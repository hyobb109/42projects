#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  MutantStack() : std::stack<T, Container>() {}

  ~MutantStack() {}

  MutantStack(const MutantStack& m) : std::stack<T, Container>(m) {
    this->c = m.c;
  }

  MutantStack& operator=(const MutantStack& m) {
    if (this != &m) {
      this->c = m.c;
    }
    return *this;
  }

  iterator begin() { return this->c.begin(); }

  const_iterator begin() const { return this->c.begin(); }

  iterator end() { return this->c.end(); }

  const_iterator end() const { return this->c.end(); }
};
#endif