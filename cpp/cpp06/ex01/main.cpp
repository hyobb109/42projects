#include <iostream>

#include "Serializer.hpp"

int main() {
  Data data;
  data.num = 42;
  data.s = "string";

  std::cout << "=====Data=====" << std::endl;
  std::cout << "&data: " << &data << std::endl;
  std::cout << "data.num: " << data.num << std::endl;
  std::cout << "data.s: " << data.s << std::endl;

  std::cout << "=====Serialize=====" << std::endl;
  uintptr_t ptr = Serializer::serialize(&data);
  std::cout << "ptr: " << ptr << std::endl;

  std::cout << "=====Deserialize=====" << std::endl;
  Data* data_ptr = Serializer::deserialize(ptr);
  std::cout << "&data_ptr: " << &data_ptr << std::endl;
  std::cout << "data_ptr->num: " << data_ptr->num << std::endl;
  std::cout << "data_ptr->s: " << data_ptr->s << std::endl;
  return 0;
}