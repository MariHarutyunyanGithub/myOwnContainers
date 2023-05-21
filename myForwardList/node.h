#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
    private:
        T item;
        Node<T>* next;
    public:
        Node();
        Node(const T&);
        Node(const T&, Node<T>*);
        ~Node();
        void setItem(const T&);
        void setNext(Node<T>*);
        T getItem() const;
        Node<T>* getNext() const;
};
#include "node.tpp"
#endif//NODE_H