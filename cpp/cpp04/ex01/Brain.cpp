#include "Brain.hpp"

Brain::Brain() { std::cout << "뇌를 채웠다!\n"; }

Brain::Brain(std::string idea) {
  for (int i = 0; i < 100; i++) ideas[i] = idea;
  std::cout << "뇌를 채웠다!\n";
}

Brain::~Brain() { std::cout << "뇌를 비웠다!\n"; }

Brain::Brain(const Brain& brain) {
  for (int i = 0; i < 100; i++) {
    ideas[i] = brain.ideas[i];
  }
  std::cout << "뇌를 복사했다!\n";
}

Brain& Brain::operator=(const Brain& brain) {
  if (this != &brain) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = brain.ideas[i];
    }
  }
  return *this;
}

const std::string* Brain::getIdeas() const { return ideas; }