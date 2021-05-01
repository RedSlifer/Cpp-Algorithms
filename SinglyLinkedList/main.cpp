#include <iostream>
#include "SinglyLinkedList.cpp"

int main()
{
    SinglyLinkedList<int> int_linked_list;

    int_linked_list.add_front(1);
    int_linked_list.add_front(2);
    int_linked_list.add_front(3);
    int_linked_list.add_front(4);
    int_linked_list.add_front(5);


    std::cout << "The front element node: " << int_linked_list.get_front()  << std::endl;
    int_linked_list.print();

    return 0;
}
