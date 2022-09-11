#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T element;
        Node* previous_link;
        Node* next_link;
    };
    
    Node* header_link;
    Node* trailer_link;
    unsigned length;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

public:
    bool is_empty();
    bool search(const T& element) const;
    int get_length() const;
    T get_front() const;
    T get_back() const;
    void insert_front(const T& element);
    void insert_back(const T& element);
    void insert_node(unsigned position, const T& element);
    void remove_front();
    void remove_back();
    void remove_node(unsigned position);
    void print();
    void reverse_print();
};

#endif
