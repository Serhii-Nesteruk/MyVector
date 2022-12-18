#pragma once

#include <functional>

template <typename T>
class MyVector final {
public:
  MyVector();
  MyVector &operator=(const MyVector &) = default;
  MyVector(const MyVector &) = default;
  ~MyVector();

  /*!
   * @brief Adding an element to the ending of the vector
   * @param T data
   * @return void nothing
   */
  void push_back(T data);
  /*!
  * @brief Adding an element to the beginning of the vector
  * @param T data
  * @return void nothing
  */
  void push_front(T data);
  /*!
   * @brief Deleting the last element of the vector.
   * @param nothing
   * @return void nothing
   */
  void pop_back();
  /*!
   * @brief Deleting the first element of the vector.
   * @param nothing
   * @return void nothing
   */
  void pop_front();
  /*!
   * @brief Clearing the vector.
   * @param nothing
   * @return void nothing
   */
  void clear();
  /*!
   * @brief Changes the logical size, the physical size does not change
   * @param const std::size_t new size
   * @return void nothing
   */
  void resize(const std::size_t newSize);
  /*!
   * @brief Reserving the memory for the vector.
   * @param const std::size_t new size
   * @return void nothing
   */
  void reserve(const std::size_t newCapacity);
  /*!
  * @brief returns true or false depending on whether the vector contains elements or is empty
  * @param nothing
  * @return void nothing
  */
  bool empty();
  /*!
  * @brief add a new element at the specified index
  * @param const T& new element, const std::size_t index
  * @return void nothing
  */
  void insert(const T &newElement, const std::size_t index);
  /*!
  * @brief Deleting the element at the given index
  * @param const std::size_t index
  * @return void nothing
  */
  void erase(const std::size_t index);
  /*!
  * @brief Deleting the elements from the startIndex to the lastIndex.
  * @param const std::size_t startIndex, const std::size_t lastIndex
  * @return void nothing
  */
  void erase(const std::size_t startIndex, const std::size_t lastIndex);
  /*!
  * @brief Deleting all the elements that satisfy the condition.
  * @param std::function<bool(T)> func
  * @return void nothing
  */
  void erase_if(std::function<bool(T)> func);
  /*!
  * @brief Deleting all the elements that are not used.
  * @param nothing
  * @return void nothing
  */
  void shrink_to_fit();
  /*!
  * @brief It shifts all the elements to the right from the given index.
  * @param const std::size_t indexFrom = 0
  * @return void nothing
  */
  void shiftToRight(const std::size_t indexFrom = 0);
  /*!
  * @brief It shifts all the elements to the left from the given index.
  * @param const std::size_t indexFrom = 0
  * @return void nothing
  */
  void shiftToLeft(const std::size_t indexFrom = 0);
  /*!
   * @brief Returning a reference to the element at the given index.
   * @param const std::size_t index
   * @return T&
   */
  T &operator[](const std::size_t index) const;
  /*!
   * @brief Deleting the element at the given index
   * @param const std::size_t index
   * @throw std::exception
   * @return T&
   */
  T &at(const std::size_t index) const;
  /*!
   * @brief It returns the first element of the vector.
   * @param nothing
   * @throw std::exception
   * @return T&
   */
  T &front();
  /*!
  * @brief It returns the last element of the vector.
  * @param nothing
  * @throw std::exception
  * @return T&
  */
  T &back();
  /*!
  * @brief It returns the capacity of the vector.
  * @param nothing
  * @return std::size_t
  */
  std::size_t capacity();
  /*!
   * @brief It returns the size of the vector.
   * @param nothing
   * @return std::size_t
   */

  std::size_t size();
private:
  /*!
    * @brief It checks if the size of the vector is equal to the capacity of the vector.If it is not, it increases the capacity of the vector.
    * @param nothing
    * @return nothing
    */

  void checkForRightSize();
private:
  std::size_t size_ = {};
  std::size_t capacity_ = {};
  T *vec = nullptr;
};

#include "MyVector.inl"
