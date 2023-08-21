#include <string>
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;


    std::cout << "=======Memory Address=====\n";
    // The memory address of the string variable
    std::cout << "str: " << &str << "\n";
    // The memory address held by stringPTR
    std::cout << "stringPTR: " << stringPTR << "\n";
    // The memory address held by stringREF
    std::cout << "stringREF: " << &stringREF << "\n";
    std::cout << "=======Value=====\n";
    // The value of the string variable
    std::cout << "str: " << str << "\n";
    // The value pointed to by stringPTR
    std::cout << "stringPTR: " << *stringPTR << "\n";
    // The value pointed to by stringREF
    std::cout << "stringREF: " << stringREF << "\n";
}