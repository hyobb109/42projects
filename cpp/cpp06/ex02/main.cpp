#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum TYPE { A_CLASS, B_CLASS, C_CLASS };

// randomly instanciates A, B or C
// and returns the instance as a Base pointer
Base* generate() {
  int type = std::rand() % 3;

  switch (type) {
    case A_CLASS:
      return new A();
    case B_CLASS:
      return new B();
    case C_CLASS:
      return new C();
    default:
      return NULL;
  }
}

// prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p) != NULL) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (std::exception& e) {
  }
  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    std::cout << "B" << std::endl;
  } catch (std::exception& e) {
  }
  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    std::cout << "C" << std::endl;
  } catch (std::exception& e) {
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  std::cout << "===Generating...===" << std::endl;
  Base* ptr = generate();
  std::cout << "Pointer Type: ";
  identify(ptr);
  std::cout << "Reference Type: ";
  identify(*ptr);
  return 0;
}
