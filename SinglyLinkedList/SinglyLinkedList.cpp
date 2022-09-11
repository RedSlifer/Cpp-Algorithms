#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include <iostream>
#include "SinglyLinkedList.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this -> head_link = nullptr;
    this -> lenght = 0;
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
int SinglyLinkedList<T>::get_lenght() const
{
    return this -> lenght;
}

template <typename T>
bool SinglyLinkedList<T>::search(const T& element) const
{
    Node* jumper = this -> head_link;

    while(jumper != nullptr)
    {
        if(jumper -> element == element)
        {
            return true;
        }

        jumper = jumper -> link;
    }
    
    return false;
}

template <typename T>
T SinglyLinkedList<T>::get_front() const
{
    return this -> head_link -> element;
}

template <typename T>
void SinglyLinkedList<T>::insert_front(const T& element)
{
    Node* new_node = new Node;  // Allocates a memory space for new node

    new_node -> element = element;  // Set the element in node
    new_node -> link = this -> head_link;    // Set the link to the next node

    head_link = new_node;    // Update the head node

    this -> lenght++;
}

template <typename T>
void SinglyLinkedList<T>::insert_back(const T& element)
{
    Node* new_node = new Node;
    Node* jumper = this -> head_link;

    new_node -> element = element;
    new_node -> link = nullptr;

    while(jumper -> link != nullptr)
    {
        jumper = jumper -> link;
    }

    jumper -> link = new_node;
    this -> lenght++;
}

template <typename T>
void SinglyLinkedList<T>::remove_front()
{
    Node* old_head = this -> head_link;  // Save the link to current head

    this -> head_link = old_head -> link;   // Defines the new head link with the old link to the second node in the list
    delete old_head;

    this -> lenght--;
}

template <typename T>
void SinglyLinkedList<T>::remove_back()
{
    Node* jumper = this -> head_link;

    for(int i = 1; i < this -> lenght - 1; i++)
    {
        jumper = jumper -> link;
    }

    Node* node_to_delete = jumper -> link;
    jumper -> link = nullptr;
    delete node_to_delete;

    this -> lenght--;
}

template <typename T>
void SinglyLinkedList<T>::remove_node(int position)
{
    if(position == 0)
    {
        remove_front();
    }
    else if (position == lenght - 1)
    {
        remove_back();
    }
    else 
    {
        Node* jumper = head_link;

        for(int i = 1; i < position; i++)
        {
            jumper = jumper -> link;
        }

        Node* node_to_delete = jumper -> link;
        jumper -> link = (jumper -> link) -> link;
        delete node_to_delete;

        this -> lenght--;
    }
}

template <typename T>
void SinglyLinkedList<T>::print() const
{
    Node* jumper = this -> head_link;

    while(jumper != nullptr)
    {
        std::cout << jumper -> element << " ";
        jumper = jumper -> link;
    }

    std::cout << std::endl;
}

#endif
