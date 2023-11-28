#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
int easyfind(T container, int target) {
  // find the first occurrence of the target in the container
  typename T::iterator iter = container.begin();

  while (iter != container.end()) {
    if (*iter == target) {
      return *iter;
    }
    ++iter;
  }
  // if no occurrence is found, throw an exception or return an error value of
  // your choice
  throw std::runtime_error("target not found");
}

#endif