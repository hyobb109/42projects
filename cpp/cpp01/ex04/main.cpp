#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char **av) {
  if (ac != 4) {
    std::cout << "Usage: ./replace <filename> <string1> <string2>";
    return 1;
  }
  // s1과 s2가 같을 때 예외처리 필요한지???
  // open the file <filename> and copies its content into a new file
  std::ifstream file(av[1]);
  std::stringstream ss;
  if (file.is_open()) {
    ss << file.rdbuf();
    std::cout << ss.str() << std::endl;
  } else {
    std::cout << "cannot open " << av[1] << std::endl;
  }
  // <filename>.replace replace every occurrnce of s1 with s2

  return 0;
}