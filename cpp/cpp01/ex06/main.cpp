#include "Harl.hpp"

int main(int ac, char **av) {
  if (ac == 2) {
    Harl harl;
    std::string level = av[1];
    harl.complain(level);
  } else {
    std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
  }
  return 0;
}