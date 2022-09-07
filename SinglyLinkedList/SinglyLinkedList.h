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
    int lenght; // List lenght

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

public:
    bool is_empty();
    int get_lenght() const;
    bool search(const T& element) const;
    T get_front() const;
    void insert_front(const T& element); 
    void insert_back(const T& element);
    void remove_front();
    void remove_back();
    void remove_node(int position); // to do
    void print() const;
};

#endif
