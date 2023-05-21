#ifndef MYLIST_H
#define MYLIST_H

#include "node.h"
template <typename T>
class MyList
{
public:
        MyList();
        MyList(const T&);
        MyList(const MyList&);
        MyList(MyList&&);
        ~MyList();
public:
    MyList& operator=(const MyList&);
    MyList& operator=(MyList&&);
    MyList operator+(const MyList&);
    MyList operator+=(const MyList&);
    friend std::ostream& operator<<(std::ostream & os, MyList<T>& obj)  
    { 
        Node<T>* current = obj.getHead();
        while(current) {    
            os << current->getItem() << " ";
            current = current->getNext();
        }        
        return os;
    }
public:
    bool insert(int, const T&);
    MyList& push_front(const T&);
    MyList& push_back(const T&);
    void pop_front();
    void pop_back();
    bool remove_at(int);
    bool remove(T&);
    bool remove(T&&);
    bool isEmpty() const;     
    void clear();
    T getEntry(int);
    bool setEntry(int, const T&);
    void setHead(Node<T>*);
    Node<T>* getHead();
    void setTail(Node<T>*);
    Node<T>* getTail() const;
    int getItemCount() const;
private:
    Node<T>* head;
    Node<T>* tail;
    int itemCount;
};

#include "myList.tpp"
#endif // MYLIST_H