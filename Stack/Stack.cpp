#ifndef STACK_CPP
#define STACK_CPP
#include <iostream>
#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
    this -> elements.reserve(1);
}

template <typename T>
Stack<T>::Stack(unsigned size)
{
    this -> elements.reserve(size);
}

template <typename T>
bool Stack<T>::is_empty()
{
    return (this -> elements.size() == 0);
}

template <typename T>
T Stack<T>::peek()
{
    return this -> elements.back();
}

template <typename T>
void Stack<T>::push(T value)
{
    this -> elements.push_back(value);
}

template <typename T>
T Stack<T>::pop()
{
    T peek_element = this -> elements.back();
    this -> elements.pop_back();

    return peek_element;
}

template <typename T>
unsigned Stack<T>::get_size() const
{
    return this -> elements.size();
}

template <typename T>
void Stack<T>::print()
{
    for (auto element : this -> elements)
    {
       std::cout << element << " ";
    }

    std::cout << std::endl;
}

#endif
