#include "../Headers/MyVector.h"
#include <stdexcept>

template <typename T>
MyVector<T>::MyVector() {
}

template <typename T>
MyVector<T>::~MyVector() {
  clear();
}

template <typename T>
void MyVector<T>::resize(const std::size_t newSize) {
  mut.lock();
  
  if (newSize > capacity_)
    reserve(newSize);
  size_ = newSize;
  

  mut.unlock();
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
  mut.lock();
  
  capacity_ = size_;
  T *temp = new T[capacity_]{};
  memcpy(temp, vec, size_ * sizeof(T));

  delete[] vec;
  vec = temp;

  mut.unlock();
}

template <typename T>
void MyVector<T>::shiftToRight(const std::size_t indexFrom) {
  mut.lock();
  for (std::size_t i = size_; i >= indexFrom; --i) 
    vec[i] = vec[i - 1];
  ++size_;
  mut.unlock();
}

template <typename T>
void MyVector<T>::shiftToLeft(const std::size_t indexFrom) {
  mut.lock();
  for (std::size_t i = indexFrom; i < size_; ++i)
    vec[i] = vec[i + 1];
  --size_;
  mut.unlock();
}

template <typename T>
void MyVector<T>::erase(const std::size_t index) {
  shiftToLeft(index);
}

template <typename T>
void MyVector<T>::erase(const std::size_t startIndex, const std::size_t lastIndex) {
  mut.lock();
  for (std::size_t i = startIndex; i <= lastIndex; ++i)
    shiftToLeft(startIndex);
  mut.unlock();
}

template <typename T>
void MyVector<T>::erase_if(std::function<bool(T)> func) //*
{
  mut.lock();
  for (std::size_t i = 0; i < size_;)
    if (func(vec[i]))
      shiftToLeft(i);
    else
      ++i;
  mut.unlock();
}

template <typename T>
bool MyVector<T>::empty() {
  return size_ <= 0;
}

template <typename T>
void MyVector<T>::push_front(T data) {
  mut.lock();
  
  checkForRightSize();
  ++size_;
  T temp1 = vec[0], temp2;
  vec[0] = data;
  for (std::size_t i = 1; i < size_; ++i) {
    temp2 = vec[i];
    vec[i] = temp1;
    if (i < size_ - 1)
      temp1 = temp2;
  }
  mut.unlock();
}

template <typename T>
void MyVector<T>::insert(const T &newElement, const std::size_t index) {
  mut.lock();
  checkForRightSize();

  shiftToRight(index);
  vec[index] = newElement;
  mut.unlock();
}

template <typename T>
void MyVector<T>::pop_back() {
  mut.lock();
  if (size_ - 1 >= 0)
    --size_;
  mut.unlock();
}

template <typename T>
void MyVector<T>::clear() {
  size_ = capacity_ = 0;
  delete[] vec;
}

template <typename T>
void MyVector<T>::pop_front() {
  mut.lock();
  T temp = vec[2];
  for (std::size_t i = 0; i < size_; ++i) {
    if (i > 0) 
      temp = vec[i];
    
    if (i < size_ - 1) {
      vec[i] = vec[i + 1];
      vec[i + 1] = temp;
    }
  }

  --size_;
  mut.unlock();
}

template <typename T>
void MyVector<T>::reserve(const std::size_t newCapacity) {
  mut.lock();

  const auto oldCapacity = capacity_;
  capacity_ = newCapacity * 2ull;
  T *temp = new T[capacity_]{};
  memcpy(temp, vec, oldCapacity * sizeof(T));

  delete[] vec;
  vec = temp;

  mut.unlock();
}

template <typename T>
void MyVector<T>::push_back(T data) {
  mut.lock();
  checkForRightSize();
  
  ++size_;
  vec[size_ - 1] = data;
  mut.unlock();
}

template <typename T>
T &MyVector<T>::operator[](const std::size_t index) const {
  return vec[index];
}

template <typename T>
T &MyVector<T>::at(const std::size_t index) const {
  if (index < size_)
    return vec[index];
  else
    throw std::out_of_range("MyVector::going beyond the vecay");
}

template <typename T>
T &MyVector<T>::back() {
  return at(size_ - 1);
}

template <typename T>
T &MyVector<T>::front() {
  return at(0);
}

template <typename T>
std::size_t MyVector<T>::capacity() {
  return capacity_;
}

template <typename T>
std::size_t MyVector<T>::size() {
  return size_;
}

template <typename T>
void MyVector<T>::checkForRightSize() {
  if (capacity_ <= size_ + 1)
    reserve(size_ + 1);
}
