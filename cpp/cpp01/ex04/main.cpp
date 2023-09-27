#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// replace every occurrnce of s1 with s2
std::string replaceAll(std::string str, std::string s1, std::string s2) {
  std::size_t found = str.find(s1);
  std::size_t s1Length = s1.length();
  std::size_t s2Length = s2.length();
  while (found != std::string::npos) {
    str.erase(found, s1Length);
    str.insert(found, s2);
    found = str.find(s1, found + s2Length);
  }
  return str;
}

int main(int ac, char **av) {
  if (ac != 4) {
    std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
    return 1;
  }
  std::string filename = av[1];
  std::string s1 = av[2];
  std::string s2 = av[3];
  if (!filename.length() || !s1.length()) {
    std::cout << "<filename> and <string1> cannot be empty!" << std::endl;
    return 1;
  }
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cout << "cannot open " << filename << std::endl;
    return 1;
  }
  std::ofstream outfile(filename + ".replace");
  if (!outfile.is_open()) {
    std::cout << "cannot open " << filename << ".replace" << std::endl;
    return 1;
  }
  std::stringstream ss;
  ss << infile.rdbuf();
  outfile << replaceAll(ss.str(), s1, s2);

  return 0;
}