#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T& a) {
  std::cout << a << " ";
}

template <typename T>
void add(T& a) {
  std::cout << ++a << " ";
}

int main() {
  int arr1[5] = {0, 1, 2, 3, 4};
  const int arr2[5] = {5, 6, 7, 8, 9};
  const std::string str_arr[5] = {"Hola", "Hello", "안녕", "Bonjour", "привет"};
  std::string str_arr2[6] = {"사과", "딸기", "복숭아",
                             "수박", "자몽", "바나나"};

  std::cout << "===int array===\n";
  ::iter(arr1, 5, print<int>);
  std::cout << "\nadding...\n";
  ::iter(arr1, 5, add<int>);
  std::cout << "\n===const int array===\n";
  ::iter(arr2, 5, print<const int>);
  std::cout << "\n===const string array===\n";
  ::iter(str_arr, 5, print<const std::string>);
  std::cout << "\n===string array===\n";
  ::iter(str_arr2, 6, print<std::string>);
  std::cout << std::endl;
  return 0;
}