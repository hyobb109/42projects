#include <string>
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;


    std::cout << "=======Memory Address=====" << std::endl;
    // The memory address of the string variable
    std::cout << "str: " << &str << std::endl;
    // The memory address held by stringPTR
    std::cout << "stringPTR: " << stringPTR << std::endl;
    // The memory address held by stringREF
    std::cout << "stringREF: " << &stringREF << std::endl;
    std::cout << "=======Value=====\n";
    // The value of the string variable
    std::cout << "str: " << str << std::endl;
    // The value pointed to by stringPTR
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    // The value pointed to by stringREF
    std::cout << "stringREF: " << stringREF << std::endl;

    return 0;
}