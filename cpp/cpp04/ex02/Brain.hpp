#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain();
  Brain(std::string idea);
  ~Brain();
  Brain(const Brain& Brain);
  Brain& operator=(const Brain& brain);
  const std::string* getIdeas() const;
  void setIdeas(std::string idea);
};

#endif