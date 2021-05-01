#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include <iostream>
#include "SinglyLinkedList.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this -> head_link = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (!is_empty())
    {
        remove_front();
    }
}

template <typename T>
bool SinglyLinkedList<T>::is_empty()
{
    return this -> head_link == nullptr;
}

template <typename T>
T SinglyLinkedList<T>::get_front() const
{
    return this -> head_link -> element;
}

template <typename T>
void SinglyLinkedList<T>::add_front(const T& element)
{
    Node* new_node = new Node;  // Allocates a memory space for new node

    new_node -> element = element;  // Set the element in node
    new_node -> link = this -> head_link;    // Set the link to the next node

    head_link = new_node;    // Update the head node
}

template <typename T>
void SinglyLinkedList<T>::remove_front()
{
    Node* old_head = this -> head_link;  // Save the link to current head

    this -> head_link = old_head -> link;   // Defines the new head link with the old link to the second node in the list
    delete old_head;
}

template <typename T>
void SinglyLinkedList<T>::print()
{
    Node* jumper = this -> head_link;

    while (jumper != nullptr)
    {
        std::cout << jumper -> element << " ";
        jumper = jumper -> link;
    }
}

template <typename T>
void SinglyLinkedList<T>::reverse_print()
{	
	if (jumper != nullptr)
	{
		reverse_print(jumper -> link);
		std::cout << jumper -> element << " ";
	}
}	

#endif
