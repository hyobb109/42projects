
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

int main(int ac, char** av) {
  // 인자 에러 처리
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
    PmergeMe p;
    std::cout << "Before: ";
    p.print(v);
    clock_t start = clock();
    p.sort(v);
    clock_t end = clock();
    std::cout << "After: ";
    p.print(v);
    printTime(v.size(), "std::vector", static_cast<double>(end - start));
    start = clock();
    p.sort(d);
    end = clock();
    printTime(d.size(), "std::deque", static_cast<double>(end - start));

  } catch (std::exception& e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}