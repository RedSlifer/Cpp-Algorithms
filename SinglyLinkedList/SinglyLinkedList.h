#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T element;  // Element saved by the node
        Node* link;  // Link to the next node
    };
    Node* head_link; // Head node of the list

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

public:
    bool is_empty();
    int lenght() const; // to do
    bool search(const T& element); // to do
    T get_front() const;
    void insert_front(const T& element); 
    void insert_back(const T& element); // to do
    void remove_front();
    void remove_back(); // to do
    void remove_node(int position); // to do
    void print();
    void reverse_print(Node* jumper = this -> head_link);
};

#endif
