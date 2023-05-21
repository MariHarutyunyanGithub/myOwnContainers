#ifndef FORWARD_LIST
#define FORWARD_LIST

#include "node.h"

template<typename T>
class FList
{
    public:
        FList();
        FList(const T&);
        FList(const FList&);
        FList(FList&&);
        ~FList();
    public:
        FList& operator=(const FList&);
        FList& operator=(FList&&);
        FList operator+(const FList&);
        FList& operator+=(const FList&);
        friend std::ostream& operator<<(std::ostream & os, FList<T>& obj)  
        { 
            Node<T>* current = obj.getHead();
            while(current != nullptr) {    
                os << current->getItem() << " ";
                current = current->getNext();
            }        
            return os;
        }

    public:
        bool insert(int, const T&);
        FList& push_front(const T&);
        bool remove_at(int);
        bool isEmpty() const;     
        void clear();
        T getEntry(int);
        void setEntry(int, const T&);
        Node<T>* getHead() const;
        void setHead(Node<T>*);
        int getItemCount() const;
        void setItemCount(int);
    private:
        Node<T>* head;
        int itemCount;
};
#include "myForwardList.tpp"
#endif//FORWARD_LIST
