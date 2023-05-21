#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "../myList/myList.h"

template<typename T>
class MyQueue 
{
private:
    MyList<T>* list;
    T top;
    int count;
public:
    MyQueue();
    ~MyQueue();
    void push(T value);
    void pop();
    T peek();
    const T& peek() const;
    int size() const;
    bool isEmpty() const;
    void clear();
    friend std::ostream& operator<<(std::ostream& os, MyQueue<T>& obj) {
        Node<T>* ptr = nullptr;
        ptr = obj.list->getHead();
        while (ptr) {
            os << ptr->getItem() << " ";
            ptr = ptr->getNext();
        }
        return os;
    }
};

#include "myQueue.tpp"
#endif // MYQUEUE_H