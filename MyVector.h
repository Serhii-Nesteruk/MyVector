#pragma once

#include <functional>

template <typename T>
class MyVector final
{
public:
    MyVector();
    MyVector& operator=(const MyVector&) = default;
    MyVector(const MyVector&) = default;
    ~MyVector();

    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void clear();
    void resize(const std::size_t newSize);
    void reserve(const std::size_t newCapacity);
    bool empty();
    void insert(const T& newElement, const std::size_t index);
    void erase(const std::size_t index);
    void erase(const std::size_t startIndex, const std::size_t lastIndex);
    void erase_if(std::function<bool(std::size_t)> func);
    void shrink_to_fit();
    void shiftToRight(const std::size_t indexFrom = 0);
    void shiftToLeft(const std::size_t indexFrom = 0);
    
    T& operator[](const std::size_t index) const;
    T& at(const std::size_t index) const;

    T& front();
    T& back();
    std::size_t capacity();
    std::size_t size();
private:
    void checkForRightSize();
private:
    std::size_t size_ = {};
    std::size_t capacity_ = {};
    T* vec = nullptr;
};

#include "MyVector.inl"
