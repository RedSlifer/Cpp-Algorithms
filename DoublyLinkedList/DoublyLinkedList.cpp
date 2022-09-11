#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP
#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    header_link = nullptr;
    trailer_link = nullptr;
    length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (!is_empty())
    {
        remove_front();
    }

    delete header_link;
    delete trailer_link;
    length = 0;
}

template <typename T>
bool DoublyLinkedList<T>::is_empty()
{
    return header_link == nullptr;
}

template <typename T>
bool DoublyLinkedList<T>::search(const T &element) const
{
    Node* jumper = header_link;

    while (jumper != nullptr)
    {
        if (jumper -> element == element)
        {
            return true;
        }

        jumper = jumper -> next_link;
    }

    return false;
}

template <typename T>
int DoublyLinkedList<T>::get_length() const
{
    return length;
}

template <typename T>
T DoublyLinkedList<T>::get_front() const
{
    return header_link -> element;
}

template <typename T>
T DoublyLinkedList<T>::get_back() const
{
    return trailer_link -> element;
}

template <typename T>
void DoublyLinkedList<T>::insert_front(const T& element)
{
    Node* new_node = new Node;
    new_node -> element = element;
    new_node -> next_link = nullptr;
    new_node -> previous_link = nullptr;

    if (header_link == nullptr)
    {
        header_link = new_node;
        trailer_link = new_node;
        
        length++;
    }
    else
    {
        header_link -> previous_link = new_node;
        new_node -> next_link = header_link;
        header_link = new_node;
        
        length++;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert_back(const T& element)
{
    Node* new_node = new Node;

    new_node -> element = element;

    trailer_link -> next_link = new_node;
    new_node -> previous_link = trailer_link;
    new_node -> next_link = nullptr;
    trailer_link = new_node;
    
    length++;
}

template <typename T>
void DoublyLinkedList<T>::insert_node(unsigned position, const T& element)
{
    if (position == 0)
    {
        insert_front(element);
        length++;
    }
    else
    {
        Node* jumper = header_link;
        Node* new_node = new Node;
        new_node -> element = element;

        for (unsigned i = 1; i <= position; i++)
        {
            jumper = jumper -> next_link;
        }

        new_node -> previous_link = jumper -> previous_link;
        jumper -> previous_link = new_node;
        new_node -> next_link = jumper;
        new_node->previous_link->next_link = new_node;
        
        length++;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove_front()
{
    Node* node_to_delete = header_link;

    header_link = header_link -> next_link;
    header_link -> previous_link = nullptr;
    delete node_to_delete;
    length--;
}

template <typename T>
void DoublyLinkedList<T>::remove_back()
{
    Node* node_to_delete = trailer_link;

    trailer_link = trailer_link -> previous_link;
    trailer_link -> next_link = nullptr;
    delete node_to_delete;
    length--;
}

template <typename T>
void DoublyLinkedList<T>::remove_node(unsigned position)
{
    Node* jumper = header_link;
    unsigned i;

    if (position == 0)
    {
        remove_front();
        length--;
    }
    else
    {
        for (i = 1; i <= position; i++)
        {
            jumper = jumper -> next_link;
        }

        Node* predecessor_node = jumper -> previous_link;
        Node* successor_node = jumper -> next_link;

        predecessor_node -> next_link = successor_node;
        successor_node -> previous_link = predecessor_node;
        delete jumper;
        length--;
    }
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node* jumper = header_link;

    while (jumper != nullptr)
    {
        std::cout << jumper -> element << " ";
        jumper = jumper -> next_link;
    }

    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::reverse_print()
{
    Node* jumper = trailer_link;

    while (jumper != nullptr)
    {
        std::cout << jumper -> element << " ";
        jumper = jumper -> previous_link;
    }

    std::cout << std::endl;
}

#endif
