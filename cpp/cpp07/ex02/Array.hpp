#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
template <typename T>
class Array {
 private:
  T* data;
  unsigned int len;

 public:
  Array() : data(new T[0]), len(0) {}
  Array(unsigned int n) : data(new T[n]), len(n) {
    for
  }
  Array(const Array& arr) : data(new T[arr.len]), len(arr.len) {
    for (unsigned int i = 0; i < len; i++) {
      data[i] = arr[i];
    }
  }
  Array& operator=(const Array& arr) {
    if (this != &arr) {
      delete[] data;
      *this = Array(arr);
    }
    return *this;
  }
  T& operator[](const unsigned int i) const {
    if (i >= len) throw std::exception();
    return data[i];
  }
  unsigned int size() const { return len; }
};

#endif