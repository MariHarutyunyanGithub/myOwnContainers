#ifndef MYSTACK_H
#define MYSTACK_H

#include "../myList/myList.h"

template<typename T>
class MyStack 
{
private:
    MyList<T>* list;
    T top;
    int count;
public:
    MyStack();
    ~MyStack();
    void push(T value);
    void pop();
    T peek();
    const T& peek() const;
    int size() const;
    bool isEmpty() const;
    void clear();
    friend std::ostream& operator<<(std::ostream& os, MyStack<T>& obj) {
        // Node<T>* ptr = nullptr;
        // ptr = obj.list->getHead();
        // while (ptr) {
        //     os << ptr->getItem() << " ";
        //     ptr = ptr->getNext();
        // }
        os << obj.list << " ";
        return os;
    }
};

#include "myStack.tpp"
#endif // MYSTACK_H





   