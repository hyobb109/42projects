
#include <ctime>

#include "PmergeMe.hpp"

static void checkArg(const std::string& av) {
  if (av.find_first_not_of("0123456789") != std::string::npos)
    throw std::runtime_error("Error");
}

static void printTime(const std::size_t& size, const std::string& type,
                      const double& duration) {
  std::cout << "Time to process a range of " << size << "elements with " << type
            << ": " << duration << " ms" << std::endl;
}

template <typename T>
static void print(const T& c) {
  for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
static double getSortingTime(T& c) {
  PmergeMe p;
  clock_t start = clock();
  p.sort(c);
  clock_t end = clock();
  return static_cast<double>(end - start);
}

int main(int ac, char** av) {
  try {
    std::vector<int> v;
    std::deque<int> d;
    if (ac < 2) throw std::runtime_error("Error");
    for (int i = 1; i < ac; i++) {
      checkArg(av[i]);
      int num = atoi(av[i]);
      if (num <= 0) throw std::runtime_error("Error");
      v.push_back(num);
      d.push_back(num);
    }
    std::cout << "Before: ";
    print(v);
    double timeV = getSortingTime(v);
    double timeD = getSortingTime(d);
    std::cout << "After: ";
    print(v);
    printTime(v.size(), "std::vector", timeV);
    printTime(d.size(), "std::deque", timeD);
  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}