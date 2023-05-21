#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
    private:
        T item;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node();
        Node(const T&);
        Node(const T&, Node<T>*, Node<T>*);
        ~Node();
        void setItem(const T&);
        void setNext(Node<T>*);
        void setPrev(Node<T>*);
        T getItem() const;
        Node<T>* getNext() const;
        Node<T>* getPrev() const;
};

#include "node.tpp"
#endif//NODE_H