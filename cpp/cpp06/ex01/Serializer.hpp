#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

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

#endif