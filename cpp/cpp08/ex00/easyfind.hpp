#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
int easyfind(T container, int target) {
  typename T::iterator iter =
      std::find(container.begin(), container.end(), target);
  if (iter == container.end()) throw std::runtime_error("target not found");
  return *iter;
}

#endif