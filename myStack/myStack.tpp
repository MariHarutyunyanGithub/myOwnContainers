template <typename T>
MyStack<T>::MyStack(): top(-1)
                     ,count(0) 
{
    list->setHead(nullptr);
};

template <typename T>
MyStack<T>::~MyStack()
{
    clear();
}

template <typename T>
void MyStack<T>::push(T value)
{
    list->push_front(value);
}

template <typename T>
void MyStack<T>::pop()
{
    if (list->isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        list->pop_front();
}

template <typename T>
T MyStack<T>::peek()
{
    if (list->isEmpty()) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return T();
    }
    return list->getHead()->getItem();
}

template <typename T>
const T& MyStack<T>::peek() const
{
    if (list->isEmpty()) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return T();
    }
    return list->getHead()->getItem();
}

template <typename T>
int MyStack<T>::size() const
{
    return list->getItemCount();
}

template <typename T>
bool MyStack<T>::isEmpty() const
{
    return list->isEmpty();
}

template <typename T>
void MyStack<T>::clear()
{
    list->clear();
}