#ifndef STACK_H
#define STACK_H
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> elements;

public:
    Stack();
    explicit Stack(unsigned size);

public:
    bool is_empty();
    T peek();
    void push(T value);
    T pop();
    [[nodiscard]] unsigned get_size() const;
    void print();
};

#endif
