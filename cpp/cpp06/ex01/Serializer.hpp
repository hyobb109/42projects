#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data {
  int a;
};

class Serializer {
 private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer& s);
  Serializer& operator=(const Serializer& s);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

Serializer::Serializer(/* args */) {}

Serializer::~Serializer() {}

#endif