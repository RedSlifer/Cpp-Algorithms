#include <iostream>
#include "Stack.cpp"

int main() {
    Stack<int> int_stack;
    Stack<std::string> string_stack;

    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    int_stack.push(4);
    int_stack.push(5);

    string_stack.push("apple");
    string_stack.push("blueberry");
    string_stack.push("watermelon");
    string_stack.push("lemon");
    string_stack.push("pear");

    std::cout << "Initial State" << std::endl;

    std::cout << "Stack of numbers" << std::endl;
    std::cout << "****************" << std::endl;
    int_stack.print();
    std::cout << int_stack.get_size() << std::endl;

    std::cout << std::endl;

    std::cout << "Stack of strings" << std::endl;
    std::cout << "****************" << std::endl;
    string_stack.print();
    std::cout << string_stack.get_size() << std::endl;

    int_stack.pop();
    int_stack.pop();
    int_stack.pop();

    string_stack.pop();
    string_stack.pop();
    string_stack.pop();

    std::cout << std::endl;

    std::cout << "State after exclude elements" << std::endl;
    std::cout << "Stack of numbers" << std::endl;
    std::cout << "****************" << std::endl;
    int_stack.print();
    std::cout << int_stack.get_size() << std::endl;

    std::cout << std::endl;

    std::cout << "Stack of strings" << std::endl;
    std::cout << "****************" << std::endl;
    string_stack.print();
    std::cout << string_stack.get_size() << std::endl;

    EXIT_SUCCESS;
}
