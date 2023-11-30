#include <iostream>

#include "Array.hpp"

#define MAX_VAL 10

// void leaks() { system("leaks a.out"); }

int main(int, char**) {
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  // atexit(leaks);

  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  Array<int> tmp = numbers;
  Array<int> test(tmp);

  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
    std::cout << "mirror[" << i << "]: " << mirror[i] << std::endl;
    std::cout << "------------------------\n";
    if (mirror[i] != numbers[i] || mirror[i] != tmp[i] ||
        mirror[i] != test[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    std::cout << "numbers[-2]" << std::endl;
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::cout << "numbers[MAX_VAL]" << std::endl;
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  delete[] mirror;
  return 0;
}