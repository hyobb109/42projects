#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
template <typename T>
class Array {
 private:
  T* data;
  unsigned int len;

 public:
  Array() : data(new T[0]), len(0) {}

  ~Array() { delete[] data; }

  Array(unsigned int n) : data(new T[n]), len(n) {
    for (unsigned int i = 0; i < n; i++) {
      data[i] = T();
    }
  }

  Array(const Array& arr) : data(new T[arr.len]), len(arr.len) {
    for (unsigned int i = 0; i < len; i++) {
      data[i] = arr[i];
    }
  }

  Array& operator=(const Array& arr) {
    if (this != &arr) {
      delete[] data;
      for (unsigned int i = 0; i < len; i++) {
        data[i] = arr[i];
      }
    }
    return *this;
  }

  T& operator[](const long long i) const {
    if (i < 0 || i >= len) throw std::out_of_range("Out of Range!");
    return data[i];
  }

  unsigned int size() const { return len; }
};

#endif